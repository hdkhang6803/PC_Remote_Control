#include <windows.h>
#include <iostream>

class MouseEventFilter : public QAbstractNativeEventFilter
{
public:
    virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override
    {
        if (eventType == "windows_generic_MSG") {
            MSG *msg = static_cast<MSG *>(message);

            if (msg->message == WM_MOUSEMOVE || msg->message == WM_LBUTTONDOWN ||
                msg->message == WM_RBUTTONDOWN || msg->message == WM_MBUTTONDOWN) {
                std::string eventType = "";

                switch (msg->message)
                {
                case WM_MOUSEMOVE:
                    eventType = "move";
                    break;
                case WM_LBUTTONDOWN:
                    eventType = "lclick";
                    break;
                case WM_RBUTTONDOWN:
                    eventType = "rclick";
                    break;
                case WM_MBUTTONDOWN:
                    eventType = "mclick";
                    break;
                }

                std::cout << eventType << " at ("
                    << GET_X_LPARAM(msg->lParam) << ", "
                    << GET_Y_LPARAM(msg->lParam) << ")\n";
            }
            else if (msg->message == WM_MOUSEWHEEL || msg->message == WM_MOUSEHWHEEL) {
                std::string eventType = "";

                switch (msg->message)
                {
                case WM_MOUSEWHEEL:
                    eventType = "vwheel";
                    break;
                case WM_MOUSEHWHEEL:
                    eventType = "hwheel";
                    break;
                }

                int scrollAmount = GET_WHEEL_DELTA_WPARAM(msg->wParam);
                if (scrollAmount != 0)
                    std::cout << eventType << " " << scrollAmount << " units\n";

                short zDelta = HIWORD(msg->wParam);
                std::cout << eventType << " " << zDelta << " units\n";
            }
        }

        return false;
    }
};
