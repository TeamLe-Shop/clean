#ifndef CLEAN_SURFACE_H
#define CLEAN_SURFACE_H

#include <curses.h>

#include <types/list.h>

/* A surface onto which elements are added.
 *
 * Elements drawn onto a Surface object can then be drawn to a curses WINDOW.
 */
struct Surface {
    ListStruct(Element*)* elements;
    size_t width;
    size_t height;
};

/* Allocates memory for and returns a new Surface. */
Surface* Surface_New(size_t width, size_t height);

/* Deallocates memory used by a Surface object. */
void Surface_Destroy(Surface* surface);

/* Adds an Element to the Surface. */
void Surface_AddElement(Surface* surface, void* element);

/* Draws all the elements to the specified window. */
void Surface_DrawToWindow(Surface* surface, WINDOW* window);

/* Pass a keypress to all elements who have a non-NULL 'input' function
 * pointer.
 */
void Surface_PassKeypress(Surface* surface, int keypress);

#endif /* SURFACE_H */
