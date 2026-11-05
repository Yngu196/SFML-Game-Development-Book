#ifndef BOOK_GAMESERVER_HPP
#define BOOK_GAMESERVER_HPP

#include <cstdint>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>

#include <thread>
#include <vector>
#include <memory>
#include <map>


class GameServer
{
	public:
		explicit							GameServer(sf::Vector2f battlefieldSize);
											~GameServer();

		void								notifyPlayerSpawn(std::int32_t aircraftIdentifier);
		void								notifyPlayerRealtimeChange(std::int32_t aircraftIdentifier, std::int32_t action, bool actionEnabled);
		void								notifyPlayerEvent(std::int32_t aircraftIdentifier, std::int32_t action);


	private:
		// A GameServerRemotePeer refers to one instance of the game, may it be local or from another computer
		struct RemotePeer
		{
									RemotePeer();

			sf::TcpSocket			socket;
			sf::Time				lastPacketTime;
			std::vector<std::int32_t>	aircraftIdentifiers;
			bool					ready;
			bool					timedOut;
		};

		// Structure to store information about current aircraft state
		struct AircraftInfo
		{
			sf::Vector2f				position;
			std::int32_t					hitpoints;
			std::int32_t                missileAmmo;
			std::map<std::int32_t, bool>	realtimeActions;
		};

		// Unique pointer to remote peers
		typedef std::unique_ptr<RemotePeer> PeerPtr;


	private:
		void								setListening(bool enable);
		void								executionThread();
		void								tick();
		sf::Time							now() const;

		void								handleIncomingPackets();
		void								handleIncomingPacket(sf::Packet& packet, RemotePeer& receivingPeer, bool& detectedTimeout);

		void								handleIncomingConnections();
		void								handleDisconnections();

		void								informWorldState(sf::TcpSocket& socket);
		void								broadcastMessage(const std::string& message);
		void								sendToAll(sf::Packet& packet);
		void								updateClientState();


	private:
		std::thread							mThread;
		sf::Clock							mClock;
		sf::TcpListener						mListenerSocket;
		bool								mListeningState;
		sf::Time							mClientTimeoutTime;

		std::size_t							mMaxConnectedPlayers;
		std::size_t							mConnectedPlayers;

		float								mWorldHeight;
		sf::FloatRect						mBattleFieldRect;
		float								mBattleFieldScrollSpeed;

		std::size_t							mAircraftCount;
		std::map<std::int32_t, AircraftInfo>	mAircraftInfo;

		std::vector<PeerPtr>				mPeers;
		std::int32_t							mAircraftIdentifierCounter;
		bool								mWaitingThreadEnd;
		
		sf::Time							mLastSpawnTime;
		sf::Time							mTimeForNextSpawn;
};

#endif // BOOK_GAMESERVER_HPP
