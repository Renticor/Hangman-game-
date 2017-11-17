#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hangman.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    man.wczytaj();
   // ui->label_kategoria->setText(QString::number(man.tablicaPlikow.size()));

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
MainWindow::~MainWindow()
{
    man.~hangman();
    delete ui;
}
void MainWindow::restartButton(bool _value)
{
    ui->Button_A->setEnabled(_value);
    ui->Button_aa->setEnabled(_value);
    ui->Button_B->setEnabled(_value);
    ui->Button_C->setEnabled(_value);
    ui->Button_cc->setEnabled(_value);
    ui->Button_D->setEnabled(_value);
    ui->Button_E->setEnabled(_value);
    ui->Button_ee->setEnabled(_value);
    ui->Button_F->setEnabled(_value);
    ui->Button_G->setEnabled(_value);
    ui->Button_H->setEnabled(_value);
    ui->Button_I->setEnabled(_value);
    ui->Button_Z->setEnabled(_value);
    ui->Button_J->setEnabled(_value);
    ui->Button_K->setEnabled(_value);
    ui->Button_L->setEnabled(_value);
    ui->Button_ly->setEnabled(_value);
    ui->Button_M->setEnabled(_value);
    ui->Button_N->setEnabled(_value);
    ui->Button_ni->setEnabled(_value);
    ui->Button_O->setEnabled(_value);
    ui->Button_u_ZAM->setEnabled(_value);
    ui->Button_P->setEnabled(_value);
    ui->Button_R->setEnabled(_value);
    ui->Button_S->setEnabled(_value);
    ui->Button_si->setEnabled(_value);
    ui->Button_T->setEnabled(_value);
    ui->Button_U->setEnabled(_value);
    ui->Button_W->setEnabled(_value);
    ui->Button_Y->setEnabled(_value);
    ui->Button_zi->setEnabled(_value);
    ui->Button_rzy->setEnabled(_value);
}
 void MainWindow::wygrana()
 {
     if(man.czyWygralem()==true && man.getBledy()<6)
     {
         QString filename;
         QImage image ;
        restartButton(false);
         filename ="Man/wygrana.png";
         bool valid=image.load(filename);
         if(valid)
         {
             image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
             ui->label_grafika->setPixmap(QPixmap::fromImage(image));
         }
         else
         {
             ui->label_grafika->setText("Nie wczytano wygranego obrazka");
         }

     }
     else if (man.getBledy()>=6)
     {
         QString filename;
         QImage image ;
        restartButton(false);
        ui->label_haslo->setText(QString::fromStdString(man.getNie_ukryte()));

         filename ="Man/przegrana.png";
         bool valid=image.load(filename);
         if(valid)
         {
             image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
             ui->label_grafika->setPixmap(QPixmap::fromImage(image));
         }
         else
         {
             ui->label_grafika->setText("Nie wczytano przegranego obrazka");
         }

     }
 }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::wisielec(unsigned _a)
{
    QString filename;
    QImage image ;
    switch(_a)
    {
    case 0:
    {
        filename ="Man/Hangman-0.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 0 obrazka");
        }

        break;
}
    case 1:
    {
        filename ="Man/Hangman-1.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 1 obrazka");
        }

        break;
    }
    case 2:
     {
        filename ="Man/Hangman-2.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 2 obrazka");
        }

        break;
    }
    case 3:
     {    filename ="Man/Hangman-3.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 3 obrazka");
        }

        break;
}
    case 4:
     {    filename ="Man/Hangman-4.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 4 obrazka");
        }

        break;
}
    case 5:
     {    filename ="Man/Hangman-5.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 5 obrazka");
        }

        break;
}
    case 6:
     {    filename ="Man/Hangman-6.png";
        bool valid=image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->label_grafika->width(),Qt::SmoothTransformation);
            ui->label_grafika->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            ui->label_grafika->setText("Nie wczytano 6 obrazka");
        }

        break;
}
    case 7:
     {
        wygrana();
        restartButton(false);
        ui->label_haslo->setText(QString::fromStdString(man.getNie_ukryte()));

        break;
}
    default:
    {
        ui->label_grafika->setText("Nie wczytano defoltowego obrazka");
        break;
}
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_Graj_clicked()
{   man.restart();
    restartButton(true);
    man.losuj();
    man.ukryj();
    man.setKategoria();
    //ui->label_kategoria->setText(QString::fromStdString(man.getKategoria()));
    ui->label_bledy->setText(QString::number(man.getBledy()));
    ui->label_wylosowane_kat->setText(QString::fromStdString(man.getKategoria()));
    ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
    wisielec(man.getBledy());
    //
    /*
    man.losuj();
    man.ukryj();
    man.setKategoria();
      */
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_A_clicked()
{
    if(ui->Button_A->isEnabled())
    {
      man.graj('A');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_A->setEnabled(false);

    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_aa_clicked()
{
    if(ui->Button_aa->isEnabled())
    {
      man.graj('Ą');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_aa->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_B_clicked()
{
    if(ui->Button_B->isEnabled())
    {
      man.graj('B');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_B->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_C_clicked()
{
    if(ui->Button_C->isEnabled())
    {
      man.graj('C');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_C->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_cc_clicked()
{
    if(ui->Button_cc->isEnabled())
    {
      man.graj('Ć');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_cc->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_D_clicked()
{
    if(ui->Button_D->isEnabled())
    {
      man.graj('D');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_D->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_E_clicked()
{
    if(ui->Button_E->isEnabled())
    {
      man.graj('E');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_E->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_ee_clicked()
{
    if(ui->Button_ee->isEnabled())
    {
      man.graj('Ę');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_ee->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_F_clicked()
{
    if(ui->Button_F->isEnabled())
    {
      man.graj('F');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_F->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_G_clicked()
{
    if(ui->Button_G->isEnabled())
    {
      man.graj('G');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_G->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_H_clicked()
{
    if(ui->Button_H->isEnabled())
    {
      man.graj('H');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_H->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_I_clicked()
{
    if(ui->Button_I->isEnabled())
    {
      man.graj('I');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_I->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_J_clicked()
{
    if(ui->Button_J->isEnabled())
    {
      man.graj('J');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_J->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_K_clicked()
{
    if(ui->Button_K->isEnabled())
    {
      man.graj('K');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_K->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_L_clicked()
{
    if(ui->Button_L->isEnabled())
    {
      man.graj('L');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_L->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_ly_clicked()
{
    if(ui->Button_ly->isEnabled())
    {
      man.graj('Ł');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_ly->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_M_clicked()
{
    if(ui->Button_M->isEnabled())
    {
      man.graj('M');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_M->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_N_clicked()
{
    if(ui->Button_N->isEnabled())
    {
      man.graj('N');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_N->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_ni_clicked()
{
    if(ui->Button_ni->isEnabled())
    {
      man.graj('Ń');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_ni->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_O_clicked()
{
    if(ui->Button_O->isEnabled())
    {
      man.graj('O');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_O->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_u_ZAM_clicked()
{
    if(ui->Button_u_ZAM->isEnabled())
    {
      man.graj('Ó');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_u_ZAM->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_P_clicked()
{
    if(ui->Button_P->isEnabled())
    {
      man.graj('P');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_P->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_R_clicked()
{
    if(ui->Button_R->isEnabled())
    {
      man.graj('R');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_R->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_S_clicked()
{
    if(ui->Button_S->isEnabled())
    {
      man.graj('S');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_S->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_si_clicked()
{
    if(ui->Button_si->isEnabled())
    {
      man.graj('Ś');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_si->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_T_clicked()
{
    if(ui->Button_T->isEnabled())
    {
      man.graj('T');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_T->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_U_clicked()
{
    if(ui->Button_U->isEnabled())
    {
      man.graj('U');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_U->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_W_clicked()
{
    if(ui->Button_W->isEnabled())
    {
      man.graj('W');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_W->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_Y_clicked()
{
    if(ui->Button_Y->isEnabled())
    {
      man.graj('Y');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_Y->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_Z_clicked()
{
    if(ui->Button_Z->isEnabled())
    {
      man.graj('Z');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_Z->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_zi_clicked()
{
    if(ui->Button_zi->isEnabled())
    {
      man.graj('Ź');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_zi->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void MainWindow::on_Button_rzy_clicked()
{
    if(ui->Button_rzy->isEnabled())
    {
      man.graj('Ż');
      ui->label_bledy->setText(QString::number(man.getBledy()));
      ui->label_haslo->setText(QString::fromStdString(man.getUkryte()));
      wisielec(man.getBledy());
      wygrana();
      ui->Button_rzy->setEnabled(false);
    }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
