#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#include <CommCtrl.h>


const char g_szClassName[] = "myWindowClass";

enum {
    STATIC_ID = 1,
    BUTTON_ID,
    EDIT_ID
};


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int isName(char * name);
int isSurname(char * surname);
int isSalary(char * salary);
int isExperience(char * experience);

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
{
    HINSTANCE hInst;
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInst = hInstance;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Radio Lead",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    HINSTANCE hInst;
    HWND hStatic;
    static HWND  hButton,  hEditName, hEditSurname, hEditSalary, hEditExperience;
    static char buf_name[100],
                buf_surname[100],
                buf_salary[100],
                buf_experience[100];

    switch(msg){
        case WM_CREATE:
            hEditName = CreateWindowEx(0,
                              WC_EDIT,
                              "Enter the name...",
                              WS_CHILD | WS_VISIBLE | WS_BORDER,
                              90, 20, 160, 23,
                              hwnd, (HMENU)EDIT_ID, hInst, NULL);
            hStatic = CreateWindowEx(0,
                                WC_STATIC,
                                "Label",
                                WS_CHILD | WS_VISIBLE,
                                10, 20, 60, 23,
                                hwnd,(HMENU)STATIC_ID,hInst,NULL);
                                SetWindowText(hStatic, TEXT("Name"));
            hEditSurname = CreateWindowEx(0,
                              WC_EDIT,
                              "Enter the surname...",
                              WS_CHILD | WS_VISIBLE | WS_BORDER,
                              90, 50, 160, 23,
                              hwnd, (HMENU)EDIT_ID, hInst, NULL);
            hStatic = CreateWindowEx(0,
                            WC_STATIC,
                            "Label",
                            WS_CHILD | WS_VISIBLE,
                            10, 50, 60, 23,
                            hwnd,(HMENU)STATIC_ID,hInst,NULL);
                            SetWindowText(hStatic, TEXT("Surname"));
            hEditSalary = CreateWindowEx(0,
                              WC_EDIT,
                              "Enter Salary...",
                              WS_CHILD | WS_VISIBLE | WS_BORDER,
                              90, 80, 160, 23,
                              hwnd, (HMENU)EDIT_ID, hInst, NULL);
            hStatic = CreateWindowEx(0,
                            WC_STATIC,
                            "Label",
                            WS_CHILD | WS_VISIBLE,
                            10, 80, 60, 23,
                            hwnd,(HMENU)STATIC_ID,hInst,NULL);
                            SetWindowText(hStatic, TEXT("Salary"));
            hEditExperience = CreateWindowEx(0,
                              WC_EDIT,
                             "Enter Job Experience...",
                              WS_CHILD | WS_VISIBLE | WS_BORDER,
                              90, 110, 160, 23,
                              hwnd, (HMENU)EDIT_ID, hInst, NULL);
            hStatic = CreateWindowEx(0,
                            WC_STATIC,
                            "Label",
                            WS_CHILD | WS_VISIBLE,
                            10, 110, 80, 23,
                            hwnd,(HMENU)STATIC_ID,hInst,NULL);
                            SetWindowText(hStatic, TEXT("Experience"));
            hButton = CreateWindowEx(0,
                              WC_BUTTON,
                              "OK",
                              WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
                              270, 60, 100, 23,
                              hwnd,
                              (HMENU)BUTTON_ID,
                              hInst,
                              NULL);

            break;
        case WM_COMMAND: {
                switch (LOWORD(wParam)) {
                    case BUTTON_ID: {
                        GetWindowText(hEditName, buf_name, sizeof(buf_name));
                        if(!isName(buf_name)){
                           MessageBox(NULL, "Name is not correct!", "Error!", MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                        GetWindowText(hEditSurname, buf_surname, sizeof(buf_surname));
                        if(!isSurname(buf_surname)){
                            MessageBox(NULL, "Surname is not correct!", "Error!", MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                        GetWindowText(hEditSalary, buf_salary, sizeof(buf_experience));
                        if(!isSalary(buf_salary)){
                            MessageBox(NULL, "Salary is not correct!", "Error!", MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                        GetWindowText(hEditExperience, buf_experience, sizeof(buf_experience));
                        if(!isExperience(buf_experience)){
                            MessageBox(NULL, "Experience is not correct!", "Error!", MB_ICONEXCLAMATION | MB_OK);
                            break;
                        }
                        char tmp[1000];
                        sprintf(tmp, "Name: %s\nSurname: %s\nSalary: %s\nExperience:%s", buf_name,buf_surname,buf_salary,buf_experience);
                        MessageBox(NULL, tmp,
                                   "Information",
                                    MB_OKCANCEL | MB_ICONQUESTION);
                        break;
                    }
                }
                break;
            }
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


int isName(char * name){
    if (strlen(name) == 0) return 0;
    for (int i = 0; i < strlen(name); i++){
        if (!isalpha(name[i])){
            return 0;
        }
    }
    return 1;
}

int isSurname(char * surname){
    if (strlen(surname) == 0) return 0;
    for (int i = 0; i < strlen(surname); i++){
        if (!isalpha(surname[i])){
            return 0;
        }
    }
    return 1;
}

int isSalary(char * salary){
    if (strlen(salary) == 0) return 0;
    for (int i = 0; i < strlen(salary); i++){
        if (!isdigit(salary[i])){
            return 0;
        }
    }
    return 1;
}
int isExperience(char * experience){
    if (strlen(experience) == 0) return 0;
    for (int i = 0; i < strlen(experience); i++){
        if (!isdigit(experience[i])){
            return 0;
        }
    }
    return 1;
}

