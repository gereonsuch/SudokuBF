#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boxes.push_back( ui->num_0 );
    boxes.push_back( ui->num_1 );
    boxes.push_back( ui->num_2 );
    boxes.push_back( ui->num_3 );
    boxes.push_back( ui->num_4 );
    boxes.push_back( ui->num_5 );
    boxes.push_back( ui->num_6 );
    boxes.push_back( ui->num_7 );
    boxes.push_back( ui->num_8 );
    boxes.push_back( ui->num_9 );
    boxes.push_back( ui->num_10 );
    boxes.push_back( ui->num_11 );
    boxes.push_back( ui->num_12 );
    boxes.push_back( ui->num_13 );
    boxes.push_back( ui->num_14 );
    boxes.push_back( ui->num_15 );
    boxes.push_back( ui->num_16 );
    boxes.push_back( ui->num_17 );
    boxes.push_back( ui->num_18 );
    boxes.push_back( ui->num_19 );
    boxes.push_back( ui->num_20 );
    boxes.push_back( ui->num_21 );
    boxes.push_back( ui->num_22 );
    boxes.push_back( ui->num_23 );
    boxes.push_back( ui->num_24 );
    boxes.push_back( ui->num_25 );
    boxes.push_back( ui->num_26 );
    boxes.push_back( ui->num_27 );
    boxes.push_back( ui->num_28 );
    boxes.push_back( ui->num_29 );
    boxes.push_back( ui->num_30 );
    boxes.push_back( ui->num_31 );
    boxes.push_back( ui->num_32 );
    boxes.push_back( ui->num_33 );
    boxes.push_back( ui->num_34 );
    boxes.push_back( ui->num_35 );
    boxes.push_back( ui->num_36 );
    boxes.push_back( ui->num_37 );
    boxes.push_back( ui->num_38 );
    boxes.push_back( ui->num_39 );
    boxes.push_back( ui->num_40 );
    boxes.push_back( ui->num_41 );
    boxes.push_back( ui->num_42 );
    boxes.push_back( ui->num_43 );
    boxes.push_back( ui->num_44 );
    boxes.push_back( ui->num_45 );
    boxes.push_back( ui->num_46 );
    boxes.push_back( ui->num_47 );
    boxes.push_back( ui->num_48 );
    boxes.push_back( ui->num_49 );
    boxes.push_back( ui->num_50 );
    boxes.push_back( ui->num_51 );
    boxes.push_back( ui->num_52 );
    boxes.push_back( ui->num_53 );
    boxes.push_back( ui->num_54 );
    boxes.push_back( ui->num_55 );
    boxes.push_back( ui->num_56 );
    boxes.push_back( ui->num_57 );
    boxes.push_back( ui->num_58 );
    boxes.push_back( ui->num_59 );
    boxes.push_back( ui->num_60 );
    boxes.push_back( ui->num_61 );
    boxes.push_back( ui->num_62 );
    boxes.push_back( ui->num_63 );
    boxes.push_back( ui->num_64 );
    boxes.push_back( ui->num_65 );
    boxes.push_back( ui->num_66 );
    boxes.push_back( ui->num_67 );
    boxes.push_back( ui->num_68 );
    boxes.push_back( ui->num_69 );
    boxes.push_back( ui->num_70 );
    boxes.push_back( ui->num_71 );
    boxes.push_back( ui->num_72 );
    boxes.push_back( ui->num_73 );
    boxes.push_back( ui->num_74 );
    boxes.push_back( ui->num_75 );
    boxes.push_back( ui->num_76 );
    boxes.push_back( ui->num_77 );
    boxes.push_back( ui->num_78 );
    boxes.push_back( ui->num_79 );
    boxes.push_back( ui->num_80 );

    getonelyone=true;

    connect(ui->findsolution, SIGNAL(clicked()), this, SLOT(findsolution()));

    /*std::vector<char> a={2,0,0,8,0,4,0,0,6,0,0,6,0,0,0,5,0,0,0,7,4,0,0,0,9,2,0,3,0,0,0,4,0,0,0,7,0,0,0,3,0,5,0,0,0,4,0,0,0,6,0,0,0,9,0,1,9,0,0,0,7,4,0,0,0,8,0,0,0,2,0,0,5,0,0,6,0,8,0,0,1};
    for(int i=0;i<a.size();i++)
        boxes[i]->setValue(a[i]);*/

    //set_status();
    setWindowTitle("SudokuBF");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::put_mat(std::vector< std::set<char> > &v){
    char k;
    for(int i=0;i<v.size();i++){
        if(v[i].size()==1){
            k=*(v[i].begin());
            boxes[i]->setValue( k );
        }else{
            boxes[i]->setValue( 0 );
        }
    }
}

void MainWindow::put_mat(std::vector<char> &v){
    for(int i=0;i<v.size();i++)
        boxes[i]->setValue( (int)v[i] );
}

bool MainWindow::check_plausibility(std::vector<std::set<char> > &v){
    for(int i=0;i<v.size();i++)
        if(v[i].size()==0)
            return false;
    return true;
}

bool MainWindow::direct_poss(std::vector<std::set<char> > &v){
    std::set<int> todel;
    int row, col, blockrow,blockcol;
    bool change=false;
    char p;

    for(int i=0;i<v.size();i++){
        todel.clear();

        row=i/9;
        col=i%9;
        blockrow=(row/3)*3;
        blockcol=(col/3)*3;

        if(v[i].size()==0)
            return false;
        else if(v[i].size()==1){
            for(int k=0;k<9;k++){
                todel.insert(row*9+k);
                todel.insert(col+k*9);
                todel.insert(blockrow*9+blockcol+ (k/3)*9+k%3);
            }
            todel.erase(i);
            p=*(v[i].begin());

            for(int k: todel)
                change|=v[k].erase(p);
        }
    }
    return change;
}




void MainWindow::print_set(std::set<char> &v){
    if(v.size()==0){
        std::cout << "[ ]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for(char i:v)
        std::cout << (int)i << ",";
    std::cout << " ]" << std::endl;
}

void MainWindow::print_vec(std::vector< std::set<char> > &v){
    std::cout << "{ ";
    for(std::set<char> i:v)
        print_set(i);
    std::cout << "}" << std::endl;
}


void MainWindow::findsolution(){
    std::vector<std::set<char> > inp;
    std::set<char> nine={1,2,3,4,5,6,7,8,9};
    int p;

    for(int i=0;i<boxes.size();i++){
        boxes[i]->setStyleSheet("color:black;");
        inp.push_back( nine );
        p=boxes[i]->value();
        if(p!=0){
            boxes[i]->setStyleSheet("color:red;");
            for(char k:inp[inp.size()-1])
                if(k!=p)
                    inp[inp.size()-1].erase(k);
        }
    }

    std::vector<std::vector<char> > solutions=solve(inp);

    if(solutions.size()==0){
        //std::cout << "Sry. no solutions found" << std::endl;
        QMessageBox msgb;
        msgb.setText("Sorry, no solutions found. ");
        msgb.exec();
    }else{
        put_mat(solutions[0]);

        if(!getonelyone)
            std::cout << solutions.size() <<  "Solutions found. " << std::endl;
    }

}

std::vector< std::vector<char> > MainWindow::solve(std::vector<std::set<char> > &v){
    std::vector< std::vector<char> > res;

    while(true){
        if(!check_plausibility(v))
            return res;

        //put_mat(v);

        if( direct_poss(v) )
            continue;

        break;
    }

    state st=get_state(v);

    if(st==incorrect)
        return res;
    else if(st==solution){
        res.push_back( get_mat(v) );
        if(getonelyone)
            return res;
    }else{
        //incomplete
        int pos=0;
        while(pos<v.size()){
            if(v[pos].size()>1)
                break;
            pos++;
        }
        std::vector<std::set<char> > cpv;
        for(char p:v[pos]){
            cpv=v;
            cpv[pos].clear();
            cpv[pos].insert(p);

            for(std::vector<char> i:solve(cpv)){
                res.push_back( i );
                if(getonelyone)
                    return res;
            }
        }

        return res;

    }


}

std::vector<char> MainWindow::get_mat(std::vector<std::set<char> > &v){
    std::vector<char> a;
    char p;
    for(std::set<char> i:v){
        p=*(i.begin());
        a.push_back(p);
    }
    return a;
}

state MainWindow::get_state(std::vector<std::set<char> > &v){
    bool anyincomplete=false;
    for(int i=0;i<v.size();i++){
        if(v[i].size()==0)
            return incorrect;
        else if(v[i].size()>1)
            anyincomplete=true;
    }
    if(anyincomplete)
        return incomplete;
    return solution;
}

void MainWindow::set_status(){
    QDateTime dze;
    dze.setDate(QDate(2021,9,30));

    int daysto=-dze.daysTo(QDateTime::currentDateTime());

    if(daysto>0)
        statusBar()->showMessage(QString("Days to DZE: ") + QString::number(daysto));
    else if(daysto==0)
        statusBar()->showMessage("Today is the day!");
    else
        statusBar()->showMessage("Miss us yet?");
}
