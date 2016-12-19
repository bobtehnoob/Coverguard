#ifndef REINHARDT_H
#define REINHARDT_H

#include "ingameelements/character.h"
#include "renderer.h"
#include "datastructures.h"
#include "ingameelements/weapons/hammer.h"

#include <string>

class Reinhardt : public Character
{
    public:
        Reinhardt(uint64_t id_, Gamestate *state, EntityPtr owner_);
        virtual ~Reinhardt() override;
        void midstep(Gamestate *state, double frametime) override;
        void render(Renderer *renderer, Gamestate *state) override;
        void interpolate(Entity *prev_entity, Entity *next_entity, double alpha) override;
        Rect getcollisionrect(Gamestate *state) override;
        Rect getstandingcollisionrect(Gamestate *state) override;
        std::string getsprite(Gamestate *state, bool mask) override;
        std::unique_ptr<Entity> clone() {return std::unique_ptr<Entity>(new Reinhardt(*this));}
        CharacterChildParameters constructparameters(uint64_t id_, Gamestate *state, EntityPtr owner_) override;
        std::string getcharacterfolder() {return "heroes/reinhardt/";}
        bool cangetinput(Gamestate *state) override {return not chargeanim.active() and not preparechargeanim.active() and Character::cangetinput(state);}
        Health getmaxhp() override;
        void useability1(Gamestate *state) override;
        void useability2(Gamestate *state) override;
        void useultimate(Gamestate *state) override;
        void stun(Gamestate *state) override;
        void begincharge() {chargeanim.reset();}
        void drawhud(Renderer *renderer, Gamestate *state) override;
        double passiveultcharge() override {return 0.4166666666666667;}
        bool weaponvisible(Gamestate *state) override {return not stunanim.active() and not chargeanim.active();}
        Heroclass heroclass() override {return REINHARDT;}

        Animation chargeanim;
        Animation preparechargeanim;
    protected:
    private:
};

#endif // REINHARDT_H
