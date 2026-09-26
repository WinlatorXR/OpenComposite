#pragma once
#include "BaseCommon.h"

enum OOVR_EVRNotificationType {
	EVRNotificationType_Transient = 0,
	EVRNotificationType_Persistent = 1,
	EVRNotificationType_Transient_SystemWithUserValue = 2,
};

enum OOVR_EVRNotificationStyle {
	EVRNotificationStyle_None = 0,
	EVRNotificationStyle_Application = 100,
	EVRNotificationStyle_Contact_Disabled = 200,
	EVRNotificationStyle_Contact_Enabled = 201,
	EVRNotificationStyle_Contact_Active = 202,
};

struct OOVR_NotificationBitmap_t;
typedef uint32_t OOVR_VRNotificationId;

class BaseNotifications {
public:
	/** Create a notification and enqueue it to be shown to the user. */
	vr::EVRNotificationError CreateNotification(vr::VROverlayHandle_t ulOverlayHandle, uint64_t ulUserValue, OOVR_EVRNotificationType type, const char* pchText, OOVR_EVRNotificationStyle style, const OOVR_NotificationBitmap_t* pImage, OOVR_VRNotificationId* pNotificationId);

	/** Destroy a notification, hiding it first if it currently shown to the user. */
	vr::EVRNotificationError RemoveNotification(OOVR_VRNotificationId notificationId);
};
