#include <minilibx-linux/mlx.h>

int main(int argc, char **argv)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "My Game");
	mlx_loop(mlx);
}

