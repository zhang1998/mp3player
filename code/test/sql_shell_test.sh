#!/bin/sh
sqlite3 -init upgradeDB.sql test.db << EOF
.table
.quit

EOF
