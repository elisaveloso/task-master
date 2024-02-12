#include "User.h"

User::User(const std::string& name, const std::string& email, const std::string& username, const std::string& password)
    : name(name), email(email), username(username), password(password) {}

const std::string& User::getName() const {
    return name;
}

void User::setName(const std::string& newName) {
    name = newName;
}

const std::string& User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

const std::string& User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& newUsername) {
    username = newUsername;
}

const std::string& User::getPassword() const {
    return password;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}