#include <raylib.h>
#include <stddef.h>
#include <stdio.h>

#define FPS 5
#define WIDTH 800
#define HEIGHT 600
#define TITLE "Sortify"


void printf_arr(int arr[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i != length - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}


int main(void) {
    int arr[10] = { 1, 4, 2, -12, 5, 4, 6, 6, 30, 9 };
    // TODO: assert that array has atleast one element
    int length = sizeof(arr) / sizeof(arr[0]);

    bool sorted = false;
    int i = 0, j = 0;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
    SetTargetFPS(FPS);
    InitWindow(WIDTH, HEIGHT, TITLE);

    const int margin = 20;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GetColor(0x181818FF));

        {
            const int screen_width = GetScreenWidth();
            const int screen_height = GetScreenHeight();
            const int bar_width = screen_width / length;

            if (!sorted) {
                if (i < length) {
                    if (j < length - 1 - i) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                        j++;
                    }
                    else {
                        j = 0;
                        i++;
                    }
                }
                else {
                    sorted = true;
                }
            }

            for (int k = 0; k < length; k++) {
                Color color = (k == j || k == j + 1) ? GREEN : RED;
                DrawRectangle(
                    (k * bar_width) + margin / 2,
                    screen_height - (arr[k] * 10 + 50),
                    bar_width - margin,
                    arr[k] * 10,
                    color
                );
            }

        }

        EndDrawing();
    }


    return 0;
}