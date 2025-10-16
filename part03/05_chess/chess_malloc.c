#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 8
#define ROWS 8

#ifdef __cplusplus
extern "C" {
#endif

int main(void);

char **add_move(int moves, char **possible_moves, char *chessboard);
char **add_move_and_set(char **possible_moves, int *moves, char *chessboard, int sy, int sx, int dy,
                        int dx, char chess_piece);
char *alloc_chessboard(void);
void dump_chessboard(char *chessboard);
void free_chessboard(char *chessboard);
void free_possible_moves(char **possible_moves);
char **generate_knight_moves(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                             char chess_piece);
char **generate_pawn_moves(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                           char chess_piece);
void generate_piece_checks(char *chessboard, short check[], int y, int x);
char **generate_piece_moves(char *chessboard, char chess_piece, int i, int j);
char **generate_piece_dir(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                            int dy_step, int dx_step, char chess_piece);
static int idx(int y, int x);
static int in_bounds(int y, int x);
short is_checkmate(char *chessboard);
void read_chessboard(char *chessboard);

int main(void)
{
    char **possible_moves = NULL, *chessboard = NULL, chess_piece;

    int i, j, move;

    chessboard = alloc_chessboard();

    read_chessboard(chessboard);

    dump_chessboard(chessboard);

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (chessboard[idx(i,j)] != '.')
            {
                chess_piece = chessboard[idx(i,j)];
                possible_moves = generate_piece_moves(chessboard, chess_piece, i, j);

                if (possible_moves == NULL)
                {
                    continue;
                }
                for (move = 0; possible_moves[move] != NULL; move++)
                {
                    printf("move %d\n", move + 1);
                    dump_chessboard(possible_moves[move]);

                    if(is_checkmate(possible_moves[move]) == 1)
                    {
                        printf("TAK\n");
                        free_chessboard(chessboard);
                        free_possible_moves(possible_moves);
                        return EXIT_SUCCESS;
                    }
                }

                free_possible_moves(possible_moves);
            }
        }
    }
    printf("NIE\n");

    free_chessboard(chessboard);
    return EXIT_SUCCESS;
}

char **add_move(int moves, char **possible_moves, char *chessboard)
{
    char **tmp = NULL;

    tmp = realloc(possible_moves, sizeof(*possible_moves) * (moves + 2));

    if (tmp == NULL)
    {
        fprintf(stderr, "%s Error: failed to allocate memory for variable 'chessboard'\n",
                __func__);
        free_chessboard(chessboard);
        exit(EXIT_FAILURE);
    }

    tmp[moves] = alloc_chessboard();

    memcpy(tmp[moves], chessboard, ROWS * COLS);

    tmp[moves + 1] = NULL;

    return tmp;
}

char **add_move_and_set(char **possible_moves, int *moves, char *chessboard, int sy, int sx, int dy,
                        int dx, char chess_piece)
{
    possible_moves = add_move(*moves, possible_moves, chessboard);
    possible_moves[*moves][idx(sy, sx)] = '*';
    possible_moves[*moves][idx(dy, dx)] = chess_piece;
    (*moves)++;
    return possible_moves;
}

char *alloc_chessboard(void)
{
    char *chessboard = NULL;

    chessboard = malloc(ROWS * COLS * sizeof(*chessboard));

    if (chessboard == NULL)
    {
        fprintf(stderr, "%s Error: failed to allocate memory for variable 'chessboard'\n",
                __func__);
        exit(EXIT_FAILURE);
    }

    return chessboard;
}

void dump_chessboard(char *chessboard)
{
    int i, j;

    printf("  ");
    for (i = 0; i < COLS; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", chessboard[i * ROWS + j]);
        }
        printf("\n");
    }
}

void dump_checks(short checks[])
{
    int i, j;

    printf("  ");
    for (i = 0; i < COLS; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", checks[idx(i, j)]);
        }
        printf("\n");
    }
}

void free_chessboard(char *chessboard)
{
    free(chessboard);
}

void free_possible_moves(char **possible_moves)
{
    int i;
    if (possible_moves == NULL)
    {
        return;
    }
    for (i = 0; possible_moves[i] != NULL; i++)
    {
        free(possible_moves[i]);
    }
    free(possible_moves);
}

char **generate_knight_moves(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                             char chess_piece)
{
    const int offsets[8][2] = {{-2, -1}, {-2, +1}, {-1, -2}, {-1, +2},
                               {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}};
    int k, ny, nx;
    char target;
    for (k = 0; k < 8; ++k)
    {
        ny = sy + offsets[k][0];
        nx = sx + offsets[k][1];
        if (!in_bounds(ny, nx))
        {
            continue;
        }
        target = chessboard[idx(ny, nx)];
        if (target == '.' || islower((unsigned char) target))
        {
            possible_moves =
                add_move_and_set(possible_moves, moves, chessboard, sy, sx, ny, nx, chess_piece);
        }
    }
    return possible_moves;
}

char **generate_pawn_moves(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                           char chess_piece)
{
    /*o jeden w gore*/
    if (sy > 0 && chessboard[idx(sy - 1, sx)] == '.')
    {
        possible_moves =
            add_move_and_set(possible_moves, moves, chessboard, sy, sx, sy - 1, sx, chess_piece);
    }
    /*o dwa w gore*/
    if (sy == 6 && chessboard[idx(sy - 1, sx)] == '.' && chessboard[idx(sy - 2, sx)] == '.')
    {
        possible_moves =
            add_move_and_set(possible_moves, moves, chessboard, sy, sx, sy - 2, sx, chess_piece);
    }
    /*bicie lewo*/
    if (sy > 0 && sx > 0 && islower((unsigned char) chessboard[idx(sy - 1, sx - 1)]))
    {
        possible_moves = add_move_and_set(possible_moves, moves, chessboard, sy, sx, sy - 1, sx - 1,
                                          chess_piece);
    }
    /*bicie prawo*/
    if (sy > 0 && sx < COLS - 1 && islower((unsigned char) chessboard[idx(sy - 1, sx + 1)]))
    {
        possible_moves = add_move_and_set(possible_moves, moves, chessboard, sy, sx, sy - 1, sx + 1,
                                          chess_piece);
    }
    return possible_moves;
}

char **generate_piece_moves(char *chessboard, char chess_piece, int y, int x)
{
    char **possible_moves = NULL;
    int moves = 0;

    switch (chess_piece)
    {
        case 'P':
            possible_moves =
                generate_pawn_moves(chessboard, possible_moves, &moves, y, x, chess_piece);
            break;

        case 'R':
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, 0, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, 0, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, 0, +1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, 0, -1, chess_piece);
            break;

        case 'B':
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, -1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, +1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, -1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, +1, chess_piece);
            break;

        case 'Q':
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, -1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, +1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, -1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, +1, chess_piece);

            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, -1, 0, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, +1, 0, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, 0, +1, chess_piece);
            possible_moves =
                generate_piece_dir(chessboard, possible_moves, &moves, y, x, 0, -1, chess_piece);
            break;

        case 'N':
            possible_moves =
                generate_knight_moves(chessboard, possible_moves, &moves, y, x, chess_piece);
            break;

        default:
            break;
    }

    return possible_moves;
}

char **generate_piece_dir(char *chessboard, char **possible_moves, int *moves, int sy, int sx,
                            int dy_step, int dx_step, char chess_piece)
{
    char target;
    int i = sy + dy_step;
    int j = sx + dx_step;

    while (in_bounds(i, j))
    {
        target = chessboard[idx(i, j)];
        if (target == '.')
        {
            possible_moves =
                add_move_and_set(possible_moves, moves, chessboard, sy, sx, i, j, chess_piece);
        }
        else if (islower((unsigned char) target))
        {
            possible_moves =
                add_move_and_set(possible_moves, moves, chessboard, sy, sx, i, j, chess_piece);
            break;
        }
        else
        {
            break;
        }
        i += dy_step;
        j += dx_step;
    }

    return possible_moves;
}

static int idx(int y, int x)
{
    return y * ROWS + x;
}

static int in_bounds(int y, int x)
{
    return y >= 0 && y < ROWS && x >= 0 && x < COLS;
}

void generate_piece_checks(char *chessboard, short check[], int y, int x)
{
    char chess_piece = chessboard[idx(y,x)];

    switch(chess_piece)
    {
        case 'P':
            /*bicie lewo*/
            if (in_bounds(y - 1, x - 1))
            {
                check[idx(y - 1,x - 1)] = 1;
            }
            /*bicie prawo*/
            if (in_bounds(y - 1, x + 1))
            {
                check[idx(y - 1,x + 1)] = 1;
            }
            break;
    }
}

short is_checkmate(char *chessboard)
{
    short check[ROWS * COLS];
    int i, j, x, y;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            check[idx(i, j)] = 0;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            generate_piece_checks(chessboard, &check[0], i, j);
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (chessboard[idx(i, j)] == 'k')
            {
                for (y = i - 1; y < i + 1; y++)
                {
                    for (x = j - 1; x < j + 1; x++)
                    {
                        if (in_bounds(y,x) && check[idx(y, x)] != 1)
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    dump_checks(&check[0]);
    return 1;
}

void read_chessboard(char *chessboard)
{
    int count = 0;
    char c;

    while (count < (ROWS * COLS) && (c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            continue;
        }
        chessboard[count] = c;
        count++;
    }
}

#ifdef __cplusplus
}
#endif
