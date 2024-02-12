#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../../src/controller/ControllerImpl.h"
#include "../../src/observer/ObserverImpl.h"
#include "../../src/model/Task.h"
#include "../../src/model/User.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

TEST_CASE("Functional Tests") {
    // Configuração do banco de dados em memória
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    REQUIRE(db.open());

    SECTION("TaskController and ConcreteObserver Interaction") {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT, completed INTEGER)");
        REQUIRE(!query.lastError().isValid());

        TaskControllerImpl controller;
        ConcreteObserver observer;

        controller.addObserver(&observer);
        controller.updateTaskStatus(true);

        REQUIRE(observer.getUpdatedTask().getCompleted() == true);

        query.exec("SELECT completed FROM tasks WHERE id = 1");
        REQUIRE(query.next());
        REQUIRE(query.value(0).toBool() == true);
    }

    SECTION("Task Creation and Assignment") {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT, completed INTEGER)");
        REQUIRE(!query.lastError().isValid());

        TaskControllerImpl controller;

        Task task = controller.createTask("Nova Tarefa");
        REQUIRE(task.getDescription() == "Nova Tarefa");
        REQUIRE_FALSE(task.getCompleted());

        User user("Usuário de Teste");
        controller.assignTask(task, user);

        REQUIRE(task.getAssignedUser().getName() == user.getName());

        query.exec("SELECT description FROM tasks WHERE id = 1");
        REQUIRE(query.next());
        REQUIRE(query.value(0).toString() == "Nova Tarefa");
    }
}
