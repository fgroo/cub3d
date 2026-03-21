*This project has been created as part of the 42 curriculum by fgroo, rtwobie.*

## Description

This project is the successor to `so_long`, another project where we created a video game using the external `MLX42` graphics library.

The core highlight of `cub3d` is the **Raycaster**, a rendering technique that creates the illusion of a third dimension while only using two-dimensional assets. Raycasting was primarily used in 20th-century video games, with its most prominent appearances in classics like *Wolfenstein 3D* and *Doom*.

### How it Works
A "ray" is essentially a continuous beam that shoots out from the player's position and iteratively checks if its path aligns with a wall. There are two popular algorithms for checking these collisions:
1. **Fixed-step Raycasting**: Checks the ray's position at constant iterational intervals.
2. **DDA (Digital Differential Analyzer)**: The algorithm we used for this project. DDA is highly optimized for grid-based maps—instead of arbitrary fixed steps, it solely checks the exact points where the ray crosses the horizontal or vertical grid lines of the map.

When a ray ultimately hits a wall grid, the algorithm calculates the exact length of the path the ray traveled. This calculated distance is then used to determine exactly how large (or tall) that specific vertical slice of the wall needs to be drawn onto the game window. 

By combining the distance of the wall hit with the direction the player is looking and a camera plane that is always perpendicular to the player's visual direction, we can accurately render the 3D effect.

While the map parsing followed a more traditional logical structure based on design choices and standard validation, the core rendering engine was a shift toward mathematical application. The raycaster is less about extensive procedural logic and more about the implementation of trigonometry and geometric projection. 

This reliance on functional mathematical formulas, rather than just basic arithmetic or standard control flow, is precisely why the use of the `<math.h>` library was explicitly permitted for this project.

### Technical Details & Configuration

The engine's behavior and rendering can be adjusted via several macros defined in `src/cub3d.h`. These allow for fine-tuning the performance and visual experience:

| Macro | Default Value | Description |
| :--- | :--- | :--- |
| `GAME_WIDTH` | `480` | Internal horizontal resolution for the 3D view. |
| `GAME_HEIGHT` | `240` | Internal vertical resolution for the 3D view. |
| `MAP_PXL_SIZE` | `320` | Size (in pixels) for the 2D minimap display. |
| `TEXTURE_WIDTH` | `64` | The width of the texture assets (must be consistent). |
| `TEXTURE_HEIGHT` | `64` | The height of the texture assets. |
| `ROT_SPEED` | `0.15` | The sensitivity/speed of the player's rotation. |
| `FOV` | `2.66` | The field of view (adjusts the camera plane length). |
| `DETAIL_LEVEL` | `1` | Affects ray density (1 = every pixel, higher = coarser). |

---

## Instructions

### Installation

To install the project, clone the repository with its submodules:
```bash
git clone --recursive https://github.com/fgroo/cub3d.git
cd cub3d
```

If the submodules `libft` and `MLX42` are empty or were not cloned properly, initialize and update them manually:
```bash
git submodule init
git submodule update --remote --recursive
```

### Compilation & Execution

Compile the project using `make`:
```bash
make
```

Run the game by providing a valid map file as an argument:
```bash
./cub3d path/to/map.cub
```

## Resources

- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)

### AI Usage
AI tools were used minimally throughout this project. Early on, they were utilized primarily as an auto-completion aid for redundant tasks and for occasional, brief explanations.

We intentionally limited our reliance on AI to prioritize independent problem-solving and critical thinking. This approach allowed us to fully focus on dissecting and truly understanding the concepts, mathematical logic, and documentation found in our primary sources, without depending on automated solutions or perfectly tailored, AI-generated explanations. 

*(Note: AI was used at the very end of the project to help translate, format, and grammar-check this `README.md` file!)*
