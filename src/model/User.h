#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    std::string email;
    std::string username;
    std::string password;

public:
    User(const std::string& name, const std::string& email, const std::string& username, const std::string& password)
        : name(name), email(email), username(username), password(password) {}
    
    const std::string& getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    const std::string& getEmail() const { return email; }
    void setEmail(const std::string& newEmail) { email = newEmail; }

    const std::string& getUsername() const { return username; }
    void setUsername(const std::string& newUsername) { username = newUsername; }

    const std::string& getPassword() const { return password; }
    void setPassword(const std::string& newPassword) { password = newPassword; }

};

#endif