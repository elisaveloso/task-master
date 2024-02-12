#include "../model/Task.h"
#include "../model/User.h"
#include <QApplication>

int main() {
    // Cria uma instância do controlador e da visualização
    TaskControllerImpl controller;
    ViewImpl view;

    // Adiciona um observador para a visualização ao controlador
    controller.addObserver(&view);

    // Conecta ao banco de dados
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");

    // Verifica se ocorreu um erro ao abrir o banco de dados
    if (!db.open()) {
        qDebug() << "Erro ao abrir o banco de dados:" << db.lastError().text();
        return 1;
    }

    // Cria a tabela 'tasks' se não existir
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT, completed INTEGER)")) {
        qDebug() << "Erro ao criar a tabela 'tasks':" << query.lastError().text();
        return 1;
    }

    // Simula a criação de uma tarefa
    Task task("Nova Tarefa");

    // Insere a tarefa na tabela 'tasks'
    query.prepare("INSERT INTO tasks (description, completed) VALUES (:description, :completed)");
    query.bindValue(":description", task.getDescription());
    query.bindValue(":completed", task.isCompleted() ? 1 : 0);
    if (!query.exec()) {
        qDebug() << "Erro ao inserir a tarefa:" << query.lastError().text();
        return 1;
    }

    // Consulta as tarefas na tabela 'tasks' e exibe na tela
    query.exec("SELECT id, description, completed FROM tasks");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString description = query.value(1).toString();
        bool completed = query.value(2).toBool();
        qDebug() << "ID:" << id << "Descrição:" << description << "Concluída:" << completed;
    }

    return query.exec();
}