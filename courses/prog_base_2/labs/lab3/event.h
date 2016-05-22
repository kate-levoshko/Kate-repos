#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "user.h"


void event_subPrint(user_t * user);
void event_unsubPrint(user_t * user);
void event_notifNewMsgPrint(user_t * user, user_t * author);
