#pragma once

#include "../observer/observer.h"
#include "../model/Task.h" // Adicione a inclusão da classe Task

class TaskView : public TaskObserver {
public:
    void taskUpdated(const Task& task) override;
    //Notificações e Alertas
    void displayNotification(const std::string& message); // exibir notificações
    //Visualizacao de progresso
    void displayProgress(int progress); // exibir progresso
    //Comentario e discussao
    void displayComment(const std::string& comment); // exibir comentários

};
