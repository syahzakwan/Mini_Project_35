#ifndef CANCEL_HPP
#define CANCEL_HPP

#include <string>

class Cancel {
public:
    void cancelReservation();
    void checkSeatStatus(int bookingID);
    void confirmCancellation(int bookingID);
};

#endif
