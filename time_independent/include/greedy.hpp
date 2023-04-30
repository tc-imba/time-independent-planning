/*
 * GREEDY
 */

#pragma once
#include "agent.hpp"

namespace pibt {

    class Greedy : public Agent {
    protected:

        void init(Node *v, Node *g = nullptr);

        // see agent.cpp about actRequesting, actExtended
        void actContracted();

        Node *nextNode();

    public:
        Greedy();

        ~Greedy();
    };

}