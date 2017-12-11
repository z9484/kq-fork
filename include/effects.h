#pragma once

/*! \brief Draw death animation
 *
 * Heh... this one's pretty obvious.  Centered on both the x and y axis.
 * This is the expanding circle animation.
 *
 * \param   target_fighter_index Target, must be >=2
 * \param   target_all_flag If ==1, then target all. If target <PSIZE then
 * target all
 *          heroes, otherwise target all enemies.
 */
void death_animation(size_t target_fighter_index, int target_all_flag);

/*! \brief Show various stats
 *
 * This is what displays damage, healing, etc in combat.
 * It's designed to be able to display an amount for one or all allies or
 * enemies.
 *
 * \param   target_fighter_index Target
 * \param   font_color Color of text
 * \param   multiple_target Multiple target flag
 */
void display_amount(size_t target_fighter_index, eFont font_color, int multiple_target);

/*! \brief Attack animation
 *
 * Draw the appropriate attack animation.  Effect is x and y centered.
 *
 * \param   target_fighter_index Target
 * \param   multiple_target Multiple target flag
 * \param   magic_effect_index Magic effect to draw
 * \param   shows Show the image
 */
void draw_attacksprite(size_t target_fighter_index, int multiple_target, size_t magic_effect_index, int shows);

/*! \brief Draw casting sprite
 *
 * Draw the casting sprite.  Effect is x and y centered.  One suggestion
 * I received was to have the casting sprite stay on screen until the
 * actual spell effect is done.  I may yet implement this.
 *
 * \param   caster_fighter_index Caster
 * \param   new_pal_color Spell look/color
 */
void draw_castersprite(size_t caster_fighter_index, int new_pal_color);

/*! \brief Draw a large sprite
 *
 * This draws a large sprite, which is meant to affect an entire group.
 * Calling the function requires supplying exact coordinates, so there
 * is no need to worry about centering here... the orient var (from the
 * effect structure) is used to determine whether to draw under or over
 * the fighters.
 *
 * \param   target_fighter_index Target
 * \param   hx x-coord
 * \param   hy y-coord
 * \param   effect_index Magic effect
 * \param   shows Show the magic sprite
 */
void draw_hugesprite(size_t target_fighter_index, int hx, int hy, size_t effect_index, int shows);

/*! \brief Draw spell sprite
 *
 * Draw the spell sprite as it affects one or all allies or enemies.  There
 * is one special var (part of the effect structure) called orient, which
 * affects the y-axis:
 * - A value of 0 says align the spell with the top of the fighter sprite.
 * - A value of 1 says center the spell.
 * - A value of 2 says align the spell with the bottom of the fighter sprite.
 *
 * The x alignment is always centered.
 *
 * \sa s_effect
 * \param   target_fighter_index Target
 * \param   multiple_target Multiple target flag
 * \param   effect_index Effect (which spell is being cast)
 * \param   shows Show the spell cast
 */
void draw_spellsprite(size_t target_fighter_index, int multiple_target, size_t effect_index, int shows);

/*! \brief Draw fighting animations
 *
 * Draw fighting animations.
 * Selects the correct image and calls draw_attacksprite()
 *
 * \sa draw_attacksprite()
 * \param   target_fighter_index Target
 * \param   fighter_index Character attacking
 * \param   multiple_target Multiple targets
 */
void fight_animation(size_t target_fighter_index, size_t fighter_index, int multiple_target);

/*! \brief Fighter status
 *
 * Just make sure the fighter in question is dead or not.  Sometimes, we
 * still want to return true if s/he is dead.
 * This happens during the casting of the life and full-life spells, in
 * combatspell().
 * deadeffect is normally 0, it is changed temporarily to 1
 *
 * \param   guy Id of character to check (index into fighter[] array)
 * \returns 1 if alive, 0 if dead
 */
int is_active(int guy);
