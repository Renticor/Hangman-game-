#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "hangman.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    hangman man;
    void wisielec(unsigned);
    void restartButton(bool);
    void wygrana();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Button_A_clicked();

    void on_Button_Graj_clicked();

    void on_Button_aa_clicked();

    void on_Button_B_clicked();

    void on_Button_C_clicked();

    void on_Button_cc_clicked();

    void on_Button_D_clicked();

    void on_Button_E_clicked();

    void on_Button_ee_clicked();

    void on_Button_F_clicked();

    void on_Button_G_clicked();

    void on_Button_H_clicked();

    void on_Button_I_clicked();

    void on_Button_Z_clicked();

    void on_Button_J_clicked();

    void on_Button_K_clicked();

    void on_Button_L_clicked();

    void on_Button_ly_clicked();

    void on_Button_M_clicked();

    void on_Button_N_clicked();

    void on_Button_ni_clicked();

    void on_Button_O_clicked();

    void on_Button_u_ZAM_clicked();

    void on_Button_P_clicked();

    void on_Button_R_clicked();

    void on_Button_S_clicked();

    void on_Button_si_clicked();

    void on_Button_T_clicked();

    void on_Button_U_clicked();

    void on_Button_W_clicked();

    void on_Button_Y_clicked();

    void on_Button_zi_clicked();

    void on_Button_rzy_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
