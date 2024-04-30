md Build
cd Build

call cmake ..
call cmake --build .

move Debug\Hanja.exe ..
cd ..
rd /s /q Build
