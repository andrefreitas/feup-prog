#ifndef SHORTCOLOURS_H
#define SHORTCOLOURS_H

#define FW FOREGROUND_RED | \
           FOREGROUND_GREEN | \
           FOREGROUND_BLUE
#define FR FOREGROUND_RED
#define FG FOREGROUND_GREEN
#define FB FOREGROUND_BLUE
#define FY FOREGROUND_RED | \
           FOREGROUND_GREEN
#define FC FOREGROUND_GREEN | \
           FOREGROUND_BLUE
#define FM FOREGROUND_BLUE | \
           FOREGROUND_RED 
#define FWI FOREGROUND_RED | \
            FOREGROUND_GREEN | \
            FOREGROUND_BLUE | \
            FOREGROUND_INTENSITY
#define FRI FOREGROUND_RED | \
            FOREGROUND_INTENSITY
#define FGI FOREGROUND_GREEN | \
            FOREGROUND_INTENSITY
#define FBI FOREGROUND_BLUE | \
            FOREGROUND_INTENSITY
#define FYI FOREGROUND_RED | \
            FOREGROUND_GREEN | \
            FOREGROUND_INTENSITY
#define FCI FOREGROUND_GREEN | \
            FOREGROUND_BLUE | \
            FOREGROUND_INTENSITY
#define FMI FOREGROUND_BLUE | \
            FOREGROUND_RED | \
            FOREGROUND_INTENSITY 
#define FNULL 0
 
#define BW BACKGROUND_RED | \
           BACKGROUND_GREEN | \
           BACKGROUND_BLUE
#define BR BACKGROUND_RED
#define BG BACKGROUND_GREEN
#define BB BACKGROUND_BLUE
#define BY BACKGROUND_RED | \
           BACKGROUND_GREEN
#define BC BACKGROUND_GREEN | \
           BACKGROUND_BLUE
#define BM BACKGROUND_BLUE | \
           BACKGROUND_RED 
#define BWI BACKGROUND_RED | \
            BACKGROUND_GREEN | \
            BACKGROUND_BLUE | \
            BACKGROUND_INTENSITY
#define BRI BACKGROUND_RED | \
            BACKGROUND_INTENSITY
#define BGI BACKGROUND_GREEN | \
            BACKGROUND_INTENSITY
#define BBI BACKGROUND_BLUE | \
            BACKGROUND_INTENSITY
#define BYI BACKGROUND_RED | \
            BACKGROUND_GREEN | \
            BACKGROUND_INTENSITY
#define BCI BACKGROUND_GREEN | \
            BACKGROUND_BLUE | \
            BACKGROUND_INTENSITY
#define BMI BACKGROUND_BLUE | \
            BACKGROUND_RED | \
            BACKGROUND_INTENSITY 
#define BNULL 0

#endif