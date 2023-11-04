#include <iostream>
#include <vector>
#include <algorithm>

class StudentSolution {
public:
    static std::vector<int> Torneo(const std::vector<int>& habilidades, int N, int K) {
        std::vector<int> players(habilidades);
        std::vector<int> wins(players.size(), 0);
        int gamesPlayed = 0;
        int winner, loser; 

        while (gamesPlayed < K) {
            std::sort(players.rbegin(), players.rend());

            winner = players[0];

            loser = players[1];

            wins[0]++;

            players.erase(players.begin() + 1);
            players.push_back(loser);

            
            if (wins[0] >= N) {
                players.push_back(winner);
                players.erase(players.begin());
            }

            gamesPlayed++;
        }

        std::vector<int> result = {loser, winner};
        return result;
    }
};

int main() {
    // Ejemplo de uso
    std::vector<int> habilidades = {1, 2, 3};
    int N = 2;
    int K = 2;https://www.onlinegdb.com/online_c++_compiler#tab-stdin

    std::vector<int> resultado = StudentSolution::Torneo(habilidades, N, K);

    std::cout << "Perdedor: " << resultado[0] << ", Ganador: " << resultado[1] << std::endl;

 return 0;
}
