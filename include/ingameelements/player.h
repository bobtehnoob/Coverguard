#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#define boolean enet_boolean
#include <enet/enet.h>
#undef boolean

#include "entity.h"
#include "datastructures.h"
#include "timer.h"

// Circular dependency
class Gamestate;
class Character;

class Player : public Entity
{
    public:
        Player(uint64_t id_, Gamestate *state);
        virtual ~Player() = default;
        void beginstep(Gamestate *state, double frametime);
        void midstep(Gamestate *state, double frametime);
        void endstep(Gamestate *state, double frametime);
        void clone(Gamestate *oldstate, Gamestate *newstate);
        void spawn(Gamestate *state);
        bool isrootobject() {return true;}
        void render(Renderer *renderer, Gamestate *state);
        void interpolate(Entity *prev_entity, Entity *next_entity, double alpha);
        std::unique_ptr<Entity> clone() {return std::unique_ptr<Entity>(new Player(*this));}
        void serialize(Gamestate *state, WriteBuffer *buffer, bool fullupdate);
        void deserialize(Gamestate *state, ReadBuffer *buffer, bool fullupdate);
        void destroy(Gamestate *state);

        Character* getcharacter(Gamestate *state);

        EntityPtr character;
        Timer spawntimer;
        Timer ultcharge;
};

#endif // PLAYER_H
