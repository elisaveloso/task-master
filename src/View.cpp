#include "ViewImpl.h"
#include <string>

using namespace std;

// View
class TaskView : public TaskObserver {
public:
    void taskUpdated(const Task& task) override {
        // Atualiza a GUI conforme necessário
        // Esta função seria implementada para refletir as mudanças na interface gráfica do usuário.
    }
};
