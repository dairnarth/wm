/* TinyWM is written by Nick Welch <nick@incise.org> in 2005 & 2011.
 *
 * This software is in the public domain
 * and is provided AS IS, with NO WARRANTY. */

#include <X11/Xlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static Display *dpy;

void
configurerequest(XEvent *e)
{
    XConfigureRequestEvent *ev = &e->xconfigurerequest;
    XWindowChanges wc;

    wc.x = ev->x;
    wc.y = ev->y;
    wc.width = ev->width;
    wc.height = ev->height;
    wc.border_width = 3;
    wc.sibling = ev->above;
    wc.stack_mode = ev->detail;
    
    XConfigureWindow(dpy, ev->window, ev->value_mask, &wc);
}

void
maprequest(XEvent *e)
{
    XMapRequestEvent *ev = &e->xmaprequest;
    unsigned long bc = 0xff0000;

    XSetWindowBorder(dpy, ev->window, bc);
    XMapWindow(dpy, ev->window);
}

int main(void)
{
    XWindowAttributes attr;
    XButtonEvent start;
    XEvent ev;

    if(!(dpy = XOpenDisplay(0x0))) return 1;

    XSync(dpy, False);
    for(;;)
    {
        XNextEvent(dpy, &ev);
        switch (ev.type) {
            case ConfigureRequest:
                configurerequest(&ev);
                break;
            case MapRequest:
                maprequest(&ev);
                break;
            default:
                break;
        }
    }
}
