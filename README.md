required: CxxTest, Boost (iostreams), gnuplot-iostream.h (utils), gnuplot, Qt

Чтобы сбилдить надо перейти из рабочий директории в build и ввести следующие команды:
cmake ..
make

В build появиться исполняемый SmartPtr: можно потыкать мою реализцию сиквенса, хранящую шаред поинтеры на инт (через терминал vscode`а почему-то не работает в отличие от обычного терминала Ubuntu)

Тесты храняться отдельными исполняемыми файлами в build/test: shared_test, weak_test, unique_test и load_test (скрины графиков нагрузочных тестов хранятся в {working_dir}/test/load_test)
Можно запустить тесты одной командой из build: ctest или make run_all_tests (за исключением нагрузочного конечно же)
