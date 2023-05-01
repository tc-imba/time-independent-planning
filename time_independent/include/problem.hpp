/*
 * template of other problems, e.g., MAPF_RANDOM, MAPF_DP
 */

#pragma once
#include "../../third_party/grid-pathfinding/graph/include/graph.hpp"
#include "agent.hpp"
#include "util.hpp"

namespace pibt {

    using Config = std::vector<Node *>;  // < loc_0[t], loc_1[t], ... >
    using Configs = std::vector<Config>;

    class Problem {
    protected:
        Graph *G;                  // graph
        Agents A;                  // all agents
        std::mt19937 *MT;          // seed
        bool solved;               // success or not
        const int max_activation;  // time step limit
        int elapsed;               // computation time (ms)

        // used for set positions randomly
        Nodes getShuffledNodes();

        Nodes getShuffledNodes(int n);

        void setStartsRandomly();

        virtual bool checkSolved() { return false; }

    public:
        Problem(Graph *_G,
                Agents _A,
                std::mt19937 * _MT,
                int _max_activation);

        virtual ~Problem();

        virtual void run();  // basic scheduler

        // getter
        bool isSolved() { return solved; }

        int getElapsed() { return elapsed; }

        // for log
        virtual std::string strProblem();
    };

}