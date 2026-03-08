# 💣 MineSweeper ![Static Badge](https://img.shields.io/badge/Original-blue?style=for-the-badge)
![Static Badge](https://img.shields.io/badge/c-grey?style=flat&logo=c)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

An implementation of the classic Mine Sweeper using 42's minilibx

## ⚒️ Compilation
Firstly, copy the repository into you computer directory

```bash
git clone https://github.com/alexpg7/MineSweeper.git MineSweeper && cd MineSweeper
```

Once copied, just execute the `make` command

```bash
make
```

> [!WARNING]
> The **mlx_linux/configure** file can lead to some problems during the compilation.
> 
> To solve them, execute
> ```bash
> chmod 777 mlx_linux/configure
> ```
> And make sure to execute `make` multiple times until the executable **``minesweeper``** is created. (These errors are a minilibx issue, which was not programmed by me)

## 🎮 Let's Play
Execute the program to see the first message. It should output this:

```output
Introduce a number (9-16) to choose grid size. Press enter to continue with default size (9x9):
```

Introduce a number between 6 and 16 to choose the difficulty.

Once introduced, a window should pop up and the instructions displayed in the terminal:

```output
INSTRUCTIONS:
        Left click: unhide cell
        Right click: put flag
        "R": restart game
```

You can left-click wherever you prefer to start the game. The first click is always safe!


![til](https://github.com/alexpg7/Images/blob/main/MineSweeper/mine1.png)

Keep playing until you win or loose. You can always restart the level by pressing ``R`` (be careful!)

![til](https://github.com/alexpg7/Images/blob/main/MineSweeper/win.png)
![til](https://github.com/alexpg7/Images/blob/main/MineSweeper/lose.png)

Finally, exit the program by clicking the window's cross or interrupting the program with ``Ctrl+C`` in the terminal.
