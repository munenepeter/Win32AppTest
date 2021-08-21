#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>





/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
//define handles for the button & textfield
HWND textfield, button, textInput, inputLabel,
brandName, amountLabel, actualAmount,
depositLabel, depositInput, withdrawalLabel,
withdrawalInput;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
char inputText[20];
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("WinGUITest"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}
 void CreateUserInterface(HWND brandName,HWND hwnd, HWND amountLabel, HWND actualAmount, HWND depositLabel, HWND depositInput, HWND withdrawalLabel, HWND withdrawalInput){


   brandName = CreateWindow("STATIC","Peter Bank",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 20, 400,25,
                            hwnd,NULL, NULL, NULL);

   amountLabel = CreateWindow("STATIC","Amount",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 60, 200,25,
                            hwnd,NULL, NULL, NULL);
   actualAmount = CreateWindow("STATIC","Ksh0.0",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            110, 60, 100,25,
                            hwnd,NULL, NULL, NULL);

   depositLabel = CreateWindow("STATIC","Deposit",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 80, 200,25,
                            hwnd,NULL, NULL, NULL);
   depositInput = CreateWindow("EDIT","",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            110, 80, 100,25,
                            hwnd,NULL, NULL, NULL);

   withdrawalLabel = CreateWindow("STATIC","Withdraw",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 100, 200,25,
                            hwnd,NULL, NULL, NULL);
   withdrawalInput = CreateWindow("EDIT","",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            110, 100, 100,25,
                            hwnd,NULL, NULL, NULL);

}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
         CreateUserInterface(brandName,hwnd, amountLabel,actualAmount,
                            depositLabel,depositInput,
                            withdrawalLabel, withdrawalInput);
        // //create a text field
        //  textfield = CreateWindow("STATIC","Hello World",
        //                           WS_VISIBLE | WS_CHILD,
        //                           20, 20, 300,25,
        //                           hwnd,NULL, NULL, NULL);
        //  //create a button
        //  button = CreateWindow("BUTTON", "First Button",
        //                        WS_VISIBLE | WS_CHILD | WS_BORDER,
        //                        20,50,200,20,
        //                        hwnd,(HMENU) 1, NULL, NULL);

        // inputLabel = CreateWindow("STATIC","Type in something",
        //                           WS_VISIBLE | WS_CHILD,
        //                           80, 80, 300,25,
        //                           hwnd,NULL, NULL, NULL);

        //   //create a text input
        //  textInput = CreateWindow("EDIT", "",
        //                           WS_VISIBLE | WS_CHILD | WS_BORDER,
        //                           20,100,400,20,
        //                           hwnd, NULL, NULL,NULL);
        //   //create button to handle the input
        //  CreateWindow("BUTTON", "GO",
        //                             WS_VISIBLE |WS_BORDER |WS_CHILD,
        //                             420,100,50,20,
        //                             hwnd, (HMENU) 2, NULL, NULL);

        break;
        //this case handles the action of clicking the buttons
        case WM_COMMAND:
          switch(LOWORD(wParam)){
           //this case handles the action of clicking the button i.e button with the value of one
              case  1:
              //this function makes a sound
               ::MessageBeep(MB_ICONERROR);
              //this function creates a dialogbox
               ::MessageBox(hwnd,"Clicked", "Button was Clicked",MB_OK);
               break;
              case 2:
                  int getInputStatus = 0;
                  getInputStatus = GetWindowText(textInput, &inputText[0], 20);
                  if(getInputStatus == 0){
                    //TODO
                  }
                  ::MessageBox(hwnd,inputText,inputText,MB_OK);

                break;

          }

        break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
