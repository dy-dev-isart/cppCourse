#include "raylibEncapsulate.h"

#include "raylib.h"

#define MAX_INPUT_CHARS     9

void demoRaylib(std::string p_sSpeed, unsigned char p_cRed, unsigned char p_cGreen, unsigned char p_cBlue)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int currentGesture = GESTURE_NONE;
    int doubleClicked = 0;
    float boxWidth = 220.f;
	Rectangle textBox = { screenWidth / 2.0f - boxWidth/2, 180, boxWidth, 50 };
    char name[MAX_INPUT_CHARS + 1] = "\0";
    name[0] = 'a';
    int framesCounter = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        currentGesture = GetGestureDetected();
        if(currentGesture == GESTURE_DOUBLETAP) 
            doubleClicked = (doubleClicked+1)%2;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground({p_cRed, p_cGreen, p_cBlue});
		if(doubleClicked !=0)
		{
            doubleClicked = enterText(name);
            framesCounter++;
            DrawRectangleRec(textBox, LIGHTGRAY);
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
            if (strlen(name) < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
             else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);

		}
        else
			DrawText(name, 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

int enterText(char* p_pcToFill)
{
    
    // Set the window's cursor to the I-Beam
    SetMouseCursor(MOUSE_CURSOR_IBEAM);

    // Get char pressed (unicode character) on the queue
    int key = GetCharPressed();

    int letterCount=strlen(p_pcToFill);
    // Check if more characters have been pressed on the same frame
    while (key > 0)
    {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 48) && (key <= 57) && (letterCount < MAX_INPUT_CHARS))
        {
            p_pcToFill[letterCount] = (char)key;
            p_pcToFill[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
            letterCount++;
        }

        key = GetCharPressed();  // Check next character in the queue
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        letterCount--;
        if (letterCount < 0) letterCount = 0;
        p_pcToFill[letterCount] = '\0';
    }
    else  if (IsKeyPressed(KEY_ENTER))
    {
        return 0;
    }
    return 1;
}
