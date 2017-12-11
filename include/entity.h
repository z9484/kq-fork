#pragma once

/*! \file
 * \brief Stuff related to entities on the map
 *
 * An entity is a hero, or an NPC.
 * \author JB
 * \date ??????
 */

using t_entity = uint32_t;

class KEntity
{
public:
    KEntity();
    ~KEntity();

    /**
     * Main entity routine
     *
     * The main routine that loops through the entity list and processes each
     * one.
     */
    void process_entities();

    /*! \brief Check entities at location
     *
     * Check for any entities in the specified coordinates. Runs combat routines if a
     * character and an enemy meet, and deactivate the enemy if it was defeated.
     *
     * @param ox x-coordinate to check
     * @param oy y-coordinate to check
     * @param who Id of entity doing the checking
     * @return index+1 of entity found or 0 if none found.
     */
    int entityat(int ox, int oy, t_entity who);

    /**
     * Initialize script
     *
     * This is used to set up an entity with a movement script so that
     * it can be automatically controlled.
     *
     * @param target_entity Entity to process
     * @param movestring The script
     */
    void set_script(t_entity target_entity, const char* movestring);

    /**
     * Set position
     *
     * Position an entity manually.
     *
     * @param en Entity to position
     * @param ex x-coord
     * @param ey y-coord
     */
    void place_ent(t_entity en, int ex, int ey);

    /**
     * Recalculate number of active entities on the map.
     *
     * This actually calculates the last index of any active entity plus one,
     * so if there are entities present, but not active, they may be counted.
     */
    void recalculateNumberOfActiveMapEntities();

    /**
     * Update the total number of entities found on the map: NPCs+players.
     */
    void setNumberOfMapEntities(size_t numEntities);

    /**
     * Get the total number of entities found on the map: NPCs+players.
     */
    size_t getNumberOfMapEntities() const;

private:

    /**
     * Used with '.cmd'
     */
    enum eCommands
    {
        COMMAND_NONE = 0,
        COMMAND_MOVE_UP = 1,
        COMMAND_MOVE_DOWN = 2,
        COMMAND_MOVE_LEFT = 3,
        COMMAND_MOVE_RIGHT = 4,
        COMMAND_WAIT = 5,
        COMMAND_FINISH_COMMANDS = 6,
        COMMAND_REPEAT = 7,
        COMMAND_MOVETO_X = 8,
        COMMAND_MOVETO_Y = 9,
        COMMAND_FACE = 10,
        COMMAND_KILL = 11,

        NUM_COMMANDS // always last
    };

    /**
     * Chase player
     *
     * Chase after the main player #0, if he/she is near. Speed up until at maximum. If the
     * player goes out of range, wander for a bit.
     *
     * @param target_entity Index of entity
     */
    void ChaseAfterMainPlayer(t_entity target_entity);

    /**
     * Check proximity
     *
     * Check to see if the target is within "rad" squares.
     * Test area is a square box rather than a circle
     * target entity needs to be within the view area
     * to be visible
     * (PH) this implementation is really odd :?
     *
     * @param eno Entity under consideration
     * @param tgt Entity to test
     * @param rad Radius to test within
     * @return 1 if near, 0 otherwise
     */
    int entity_near(t_entity eno, t_entity tgt, int rad);

    /**
     * Run script
     *
     * This executes script commands.  This is from Verge1.
     *
     * @param target_entity Entity to process
     */
    void entscript(t_entity target_entity);

    /**
     * Party following leader
     *
     * This makes any characters (after the first) follow the leader.
     */
    void follow(int tile_x, int tile_y);

    /**
     * Read a command and parameter from a script
     *
     * This processes entity commands from the movement script.
     * This is from Verge1.
     *
     * Script commands are:
     * - U,R,D,L + param:  move up, right, down, left by param spaces
     * - W+param: wait param frames
     * - B: start script again
     * - X+param: move to x-coord param
     * - Y+param: move to y-coord param
     * - F+param: face direction param (0=S, 1=N, 2=W, 3=E)
     * - K: kill (remove) entity
     *
     * @param target_entity Entity to process
     */
    void getcommand(t_entity target_entity);

    /**
     * Generic movement
     *
     * Set up the entity vars to move in the given direction
     *
     * @param target_entity Index of entity to move
     * @param dx tiles to move in x direction
     * @param dy tiles to move in y direction
     */
    int move(t_entity target_entity, int dx, int dy);

    /**
     * Check for obstruction
     *
     * Check for any map-based obstructions in the specified coordinates.
     *
     * @param origin_x Original x-coord position
     * @param origin_y Original y-coord position
     * @param move_x Amount to move -1..+1
     * @param move_y Amount to move -1..+1
     * @param check_entity Whether to return 1 if an entity is at the target
     * @return 1 if path is obstructed, 0 otherwise
     */
    int obstruction(int origin_x, int origin_y, int move_x, int move_y, int check_entity);

    /**
     * Read an int from a script
     *
     * This parses the movement script for a value that relates
     * to a command.  This is from Verge1.
     *
     * @param target_entity Entity to process
     */
    void parsems(t_entity target_entity);

    /**
     * Process movement for player
     *
     * This is the replacement for process_controls that used to be in kq.c
     * I realized that all the work in process_controls was already being
     * done in process_entity... I just had to make this exception for the
     * player-controlled dude.
     */
    void player_move(void);

    /**
     * Actions for one entity
     *
     * Process an individual active entity. If the entity in question is #0 (main character)
     * and the party is not automated, then allow for player input.
     *
     * @param target_entity Index of entity
     */
    void process_entity(t_entity target_entity);

    /**
     * Adjust movement speed
     *
     * This has to adjust for each entity's speed.
     * 'Normal' speed appears to be 4.
     *
     * @param target_entity Index of entity
     */
    void speed_adjust(t_entity target_entity);

    /**
     * Move entity towards target
     *
     * When entity is in target mode (MM_TARGET) move towards the goal.  This is
     * fairly simple; it doesn't do clever obstacle avoidance.  It simply moves
     * either horizontally or vertically, preferring the _closer_ one. In other
     * words, it will try to get on a vertical or horizontal line with its target.
     *
     * @param target_entity Index of entity
     */
    void target(t_entity target_entity);

    /**
     * Move randomly
     *
     * Choose a random direction for the entity to walk in and set up the vars to do so.
     *
     * @param target_entity Index of entity to move
     */
    void wander(t_entity target_entity);

private:
    int noe;
};

extern KEntity kEntity;
