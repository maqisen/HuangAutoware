#include <iostream>
#include <sqlite3.h>  // Include SQLite3 header

struct TakeOverRecord {
    int id;
    double latitude;
    double longitude;
    double heading;
    double speed;
    int occurrence_count;
};

void insertRecord(sqlite3* db, const TakeOverRecord& record) {
    const char* sql_insert = "INSERT INTO takeover_records (latitude, longitude, heading, speed, occurrence_count) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql_insert, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare insert: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_double(stmt, 1, record.latitude);
    sqlite3_bind_double(stmt, 2, record.longitude);
    sqlite3_bind_double(stmt, 3, record.heading);
    sqlite3_bind_double(stmt, 4, record.speed);
    sqlite3_bind_int(stmt, 5, record.occurrence_count);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Record inserted successfully." << std::endl;
    }

    sqlite3_finalize(stmt);
}

void printAllRecords(sqlite3* db) {
    const char* sql_select = "SELECT id, latitude, longitude, heading, speed, occurrence_count FROM takeover_records;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare select: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::cout << "\n--- All TakeOver Records ---\n";

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        double lat = sqlite3_column_double(stmt, 1);
        double lon = sqlite3_column_double(stmt, 2);
        double heading = sqlite3_column_double(stmt, 3);
        double speed = sqlite3_column_double(stmt, 4);
        int count = sqlite3_column_int(stmt, 5);

        std::cout << "ID: " << id
                  << ", Latitude: " << lat
                  << ", Longitude: " << lon
                  << ", Heading: " << heading
                  << ", Speed: " << speed
                  << ", Occurrences: " << count << std::endl;
    }

    sqlite3_finalize(stmt);
}

int main() {
    sqlite3* db;
    int exit_code;

    // Database connection
    exit_code = sqlite3_open("example.db", &db);

    if (exit_code) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Database opened successfully!" << std::endl;
    }

    // Create table
    const char* sql_create_table =
        "CREATE TABLE IF NOT EXISTS takeover_records ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "latitude REAL NOT NULL, "
        "longitude REAL NOT NULL, "
        "heading REAL NOT NULL, "
        "speed REAL NOT NULL, "
        "occurrence_count INTEGER NOT NULL);";

    char* error_message;
    exit_code = sqlite3_exec(db, sql_create_table, nullptr, nullptr, &error_message);

    if (exit_code != SQLITE_OK) {
        std::cerr << "Error creating table: " << error_message << std::endl;
        sqlite3_free(error_message);
    } else {
        std::cout << "Table created successfully." << std::endl;
    }

    // Test
    TakeOverRecord rec = {0, 48.739, -122.485, 90.0, 35.5, 1};
    insertRecord(db, rec);
    printAllRecords(db);

    // Close database
    sqlite3_close(db);
    return 0;
}
