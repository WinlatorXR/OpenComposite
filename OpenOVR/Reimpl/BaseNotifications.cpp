#include "stdafx.h"
#define BASE_IMPL
#include "BaseNotifications.h"

using namespace vr;

// Notifications are never shown, so accept them silently
EVRNotificationError BaseNotifications::CreateNotification(VROverlayHandle_t ulOverlayHandle, uint64_t ulUserValue, OOVR_EVRNotificationType type, const char* pchText, OOVR_EVRNotificationStyle style, const OOVR_NotificationBitmap_t* pImage, OOVR_VRNotificationId* pNotificationId)
{
	if (pNotificationId)
		*pNotificationId = 0;

	return VRNotificationError_OK;
}
EVRNotificationError BaseNotifications::RemoveNotification(OOVR_VRNotificationId notificationId)
{
	return VRNotificationError_OK;
}
