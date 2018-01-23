#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <QSpinBox>
#include <set>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

enum state{
    incorrect,
    incomplete,
    solution
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool getonelyone;
    std::vector< QSpinBox* > boxes;

    void print_vec(std::vector< std::set<char> > &v);
    void print_set(std::set<char> &v);

    void put_mat(std::vector<std::set<char> > &v);
    void put_mat(std::vector<char> &v);

    bool check_plausibility(std::vector<std::set<char> > &v);
    state get_state(std::vector<std::set<char> > &v);

    bool direct_poss(std::vector<std::set<char> > &v);

    std::vector<char> get_mat(std::vector<std::set<char> > &v);

    std::vector< std::vector<char> > solve(std::vector<std::set<char> > &v);

    void set_status();

    void config_nums(QSpinBox *b);


public slots:
    void findsolution();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
