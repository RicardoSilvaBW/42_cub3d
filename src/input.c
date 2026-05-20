#include <X11/keysym.h>

//
static void stt_key_event(int keycode, t_data *data)
{
    int esc_key;

    esc_key = 65307;
    if (keycode == esc_key)
        clean(data);
}

void  key_press(int keycode, t_data *data)
{
    stt_key_event(keycode, data);
    data->keys.right_arrow = (keycode == XK_Right);
    data->keys.left_arrow = (keycode == XK_Left);
    data->keys.up_arrow = (keycode == XK_Up);
    data->keys.down_arrow = (keycode == XK_Down);
    data->keys.w = (keycode == XK_w);
    data->keys.a = (keycode == XK_a);
    data->keys.s = (keycode == XK_s);
    data->keys.d = (keycode == XK_d);
}

void  key_release(int keycode, t_data *data)
{
    if (keycode == XK_Right)
        data->keys.right_arrow = false;
    if (keycode == XK_Left)
        data->keys.left_arrow = false;
    if (keycode == XK_Up)
        data->keys.up_arrow = false;
    if (keycode == XK_Down)
        data->keys.down_arrow = false;
    if (keycode == XK_w)
        data->keys.w = false;
    if (keycode == XK_a)
        data->keys.a = false;
    if (keycode == XK_s)
        data->keys.s = false;
    if (keycode == XK_d)
        data->keys.d = false;
}
