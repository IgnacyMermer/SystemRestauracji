#include "addingredient.h"
#include "ui_addingredient.h"
#include <string>
#include "../data/PostData.h"
#include <QMessageBox>

AddIngredient::AddIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddIngredient)
{
    ui->setupUi(this);
}

AddIngredient::~AddIngredient()
{
    delete ui;
}

void AddIngredient::on_pushButton_clicked()
{
    std::string name = ui->textEdit_name->toPlainText().toStdString();
    std::string shortName = ui->lineEdit_shortName->text().toStdString();
    std::string countStr = ui->lineEdit_count->text().toStdString();
    std::string body = "{\"productsCount\": "+countStr+", \"shortName\": \""+shortName+"\", \"name\": \""+name+"\"}";
    PostData postData = PostData("http://localhost:3000/meals/addnewingredient", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        this->hide();
        QMessageBox::information(this, "Success", "Ingredient added successfully");
    }
    else{
        QMessageBox::information(this, "Error", "Error during adding new ingredient. Try again later");
    }
}

