#ifndef _WORLD_H
#define _WORLD_H

#include "Node.h"
#include "constants.h"
#include "Player.h"

typedef Node* NodePtr;

class World {

    // the array holding all nodes
    NodePtr nodes[MAX_NODES];
    Player *player;

    public:

    World() {
        // memset(nodes, NULL, MAX_NODES * sizeof(NodePtr));
    }

    void addNode(Node* node) {
        // iterate over node array to find first empty slot
        for (uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] == NULL) {
                nodes[i] = node;
                break;
            }
        }
    }

    void cleanup() {
        // iterate over node array and remove "dead" nodes
        for (uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL && nodes[i]->dead()) {
                delete nodes[i];
                nodes[i] = NULL;
            }
        }
    }

    void tick() {
        for(uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL) {
                nodes[i]->tick();
            }
        }
    }

    void render(const Canvas& canvas) {
        for(uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL) {
                nodes[i]->render(canvas);
            }
        }
    }

    NodePtr* getNodes() { return nodes; }

    uint16_t getNodeCount() {
        uint16_t count = 0;
        for(uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL) {
                count++;
            }
        }
        return count;
    }

    void setPlayer(Player* player) { this->player = player; }
    Player* getPlayer() { return player; }

};

#endif