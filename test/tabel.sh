sqlite3 -init upgradeDB.sql test.db << EOF
.table
select * from COMPANY1;
.quit

EOF


