#include "InputSelectionTask.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <WinUser.h>

InputSelectionTask::InputSelectionTask(QObject *parent) : QObject(parent) {}

void InputSelectionTask::doWork()
{
	while (1) {
		Sleep(50); // give other programs time to run

		SHORT control = GetAsyncKeyState(VK_CONTROL);
		SHORT insertKey = GetAsyncKeyState(VK_INSERT);

		bool controlPressed = control != 0;
		bool insertPressed = insertKey != 0;

		if (controlPressed && insertPressed)
		{
			if (OpenClipboard(NULL))
			{
				int key_count = 4;
				INPUT* input = new INPUT[key_count];
				for (int i = 0; i < key_count; i++)
				{
					input[i].ki.dwFlags = 0;
					input[i].type = INPUT_KEYBOARD;
				}

				input[0].ki.wVk = VK_CONTROL;
				input[0].ki.wScan = MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC);

				input[1].ki.wVk = 'c';
				input[1].ki.wScan = MapVirtualKey(0x56, MAPVK_VK_TO_VSC);

				input[2].ki.dwFlags = KEYEVENTF_KEYUP;
				input[2].ki.wVk = input[0].ki.wVk;
				input[2].ki.wScan = input[0].ki.wScan;

				input[3].ki.dwFlags = KEYEVENTF_KEYUP;
				input[3].ki.wVk = input[1].ki.wVk;
				input[3].ki.wScan = input[1].ki.wScan;


				if (SendInput(key_count, (LPINPUT)input, sizeof(INPUT)))
				{
					HGLOBAL hglb = GetClipboardData(CF_TEXT);
					LPSTR lpstr = (LPSTR)GlobalLock(hglb);

					if (lpstr != NULL)
					{
						QString text(lpstr);

						static QString prevText;
						if (prevText != text && !text.isEmpty())
						{
							emit textSelected(text);
							prevText = text;
						}
					}
					GlobalUnlock(hglb);
					CloseClipboard();
				}
			}
		}
	}
}
