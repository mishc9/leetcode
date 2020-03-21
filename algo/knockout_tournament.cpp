//
// Created by Михаил Степанов on 08.03.2020.
//

#include <iostream>
#include <vector>

using namespace std;


// P(X reaches n-th round) = P(x reaches (n-1)-th round) * sum (for all Y) (X wins Y) * (Y in X's rivals in n-th round)
// But the correct solution seems to be https://math.stackexchange.com/questions/819314/probability-of-team-winning-in-a-single-elimination-tournament
// But in this solution we ignore the fact that the given probability combinations aren't independent
// Similar but simpler task: https://math.stackexchange.com/a/3233970/691023

using Table = vector<vector<float>>;


vector<float> Normalize(const vector<float> &input) {
    vector<float> output(input.size());
    float sum = 0;
    for (int i = 0; i < input.size(); ++i) {
        sum += input[i];
        output[i] = input[i];
    }
    for (int i = 0; i < input.size(); ++i) {
        output[i] /= sum;
    }
    return output;
}


vector<float> ProbToWin(int n_rounds, int n_teams, const Table &odds) {
    vector<float> prob_to_reach_nth_round(n_teams);
    vector<float> prob_to_reach_nth_round_norm(n_teams);
    Table prob_y_and_x_rivals(n_teams);
    // initial state: all teams plays in tournament
    for (int i = 0; i < n_teams; ++i) {
        prob_to_reach_nth_round[i] = 1;
    }
    // initial state: equal prob. to play with each team except itself
    for (int i = 0; i < n_teams; ++i) {
        vector<float> subv(n_teams);
        prob_y_and_x_rivals[i] = subv;
        for (int j = 0; j < n_teams; ++j) {
            if (i == j) {
                prob_y_and_x_rivals[i][j] = 0;
            } else {
                prob_y_and_x_rivals[i][j] = (float) 1 / (float) (n_teams - 1);
            }
        }
    }

    for (int i = 0; i < n_rounds; ++i) {
        for (int team = 0; team < n_teams; ++team) {
            float win_round_expectation = 0;
            for (int rival = 0; rival < n_teams; ++rival) {
                win_round_expectation += odds[team][rival] * prob_y_and_x_rivals[team][rival];
            }
            prob_to_reach_nth_round[team] = prob_to_reach_nth_round[team] * win_round_expectation;
        }
        // prob_to_reach_nth_round_norm = Normalize(prob_to_reach_nth_round);

        for (int team = 0; team < n_teams; ++team) {
            vector<float> prob_for_team(n_teams);
            for (int rival = 0; rival < n_teams; ++rival) {
                if (team == rival) {
                    prob_for_team[rival] = 0;
                } else {
                    prob_for_team[rival] = prob_to_reach_nth_round[team] * prob_to_reach_nth_round[rival];
                }
            }
            prob_for_team = Normalize(prob_for_team);
            for (int rival = 0; rival < n_teams; ++rival) {
                prob_y_and_x_rivals[team] = prob_for_team;
            }
        }
    }
    return prob_to_reach_nth_round;
}


ostream &operator<<(ostream &stream, const vector<float> &vec) {
    for (const auto &value : vec) {
        cout << value << " ";
    }
    return stream;
}


vector<float> VictoryForTournament(vector<vector<pair<int, int>>> schedule, Table odds) {
    for (auto const &round : schedule) {
        for (auto const &match : round) {

        }
    }
}


int main() {
    float prob = float(1) / float(2);
    cout << ProbToWin(2,
                      4,
                      {
                              {0.5,  prob, prob, prob},
                              {prob, 0.5,  prob, prob},
                              {prob, prob, 0.5,  prob},
                              {prob, prob, prob, 0.5}
                      }
    );
    cout << endl;
    cout << ProbToWin(2,
                      4,
                      {
                              {0.5, 1,   1,   1},
                              {0,   0.5, 0.5, 0.5},
                              {0,   0.5, 0.5, 0.5},
                              {0,   0.5, 0.5, 0.5}
                      }
    );
    return 0;
}
