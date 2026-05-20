#include <unistd.h>
#include "libft.h"


static void stt_init_hooks(t_data *data)
{
    mlx_hook(data->win, 2, 1L << 0, key_press, data);
    mlx_hook(data->win, 3, 1L << 1, key_release, data);
    mlx_hook(data->win, 17, 0, clean(), data);
}

static int  stt_init_mlx(t_data *data)
{
    ft_memset(data, 0);
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        write(2, "Error: mlx init fail.\n", 11);
        return (1);
    }
    data->win = mlx_new_window(data->mlx, data->win_width, data->w_height, "Backrooms");
    if (!data->win)
    {
        mlx_destroy_display(data->mlx);
        write(2, "Error: mlx new window fail.\n", 28);
        return (1);
    }
    data->win_width = 1920;
    data->win_height = 1080;
}

int init(t_data *data)
{
    if (stt_init_mlx(data))
        return (1);
    stt_init_hooks(data);
    if (parse(data))
        return (1);
    return (0);
}
