#pragma once
#include <string>

class ImportCalendar {
public:
    static void drawImport();

    static void setImport(bool set) {
        openImport = set;
    }

    static bool getImport() {
        return openImport;
    }
private:
    ImportCalendar() {}
    ImportCalendar(const  ImportCalendar&) = delete;
    void operator=(const  ImportCalendar&) = delete;

    static bool openImport;

};