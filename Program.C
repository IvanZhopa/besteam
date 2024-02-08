using System;
using System.Collections.Generic;
using System.Text;
using System.Text.Encodings;

class User
{
    public string Email { get; set; }
    public string Password { get; set; }
}

class UserRegistration
{
    private List<User> users = new List<User>();
    public bool RegisterUser(string email, string password)
    {
        // Проверка корректности электронной почты и пароля
        if (IsValidEmail(email) && IsStrongPassword(password))
        {
            users.Add(new User { Email = email, Password = password });
            Console.WriteLine("Пользователь успешно зарегистрирован");
            return true;
        }
        else
        {
            Console.WriteLine("Ошибка регистрации пользователя");
            return false;
        }
    }

    public void renamePass(string email, string password)
    {
        foreach (var user in users) if (user.Email == email) user.Password = password;
    }

    public bool isUser(string email)
    {
        foreach (var user in users)
        {
            if (user.Email == email) return true;
        }
        return false;
    }

    private bool IsValidEmail(string email)
    {
        // Простейшая проверка формата email для примера
        return email.Contains("@");
    }

    private bool IsStrongPassword(string password)
    {
        // Проверка надежности пароля (просто для примера - обычно используются более сложные методы)
        return password.Length >= 8;
    }

    public bool LoginUser(string email, string password)
    {
        foreach (var user in users)
        {
            if (user.Email == email && user.Password == password)
            {
                Console.WriteLine("Вход выполнен успешно");
                return true;
            }
        }
        Console.WriteLine("Неверный адрес электронной почты или пароль");
        return false;
    }
}

class Program
{
    static void Main()
    {
        Console.OutputEncoding = Encoding.UTF8;
        UserRegistration userRegistration = new UserRegistration();

        while (true)
        {
            Console.WriteLine("Выберите действие:\n1 - Регистрация\n2 - Вход\n3 - Восстановить пароль\n0 - Выход");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Console.WriteLine("Введите адрес электронной почты:");
                    string regEmail = Console.ReadLine();

                    Console.WriteLine("Введите пароль:");
                    string regPassword = Console.ReadLine();

                    userRegistration.RegisterUser(regEmail, regPassword);
                    break;

                case "2":
                    Console.WriteLine("Введите адрес электронной почты:");
                    string loginEmail = Console.ReadLine();

                    Console.WriteLine("Введите пароль:");
                    string loginPassword = Console.ReadLine();

                    userRegistration.LoginUser(loginEmail, loginPassword);
                    break;

                case "3":
                    Console.WriteLine("Введите адрес электронной почты:");
                    string newEmail;
                    if (userRegistration.isUser(newEmail = Console.ReadLine()))
                    {
                        Console.WriteLine("Введите новый пароль:");
                        userRegistration.renamePass(newEmail, Console.ReadLine());
                        Console.WriteLine("Пароль успешно изменен");
                    }
                    else Console.WriteLine("Такого пользователя не существует");

                    break;

                case "0":
                    return;

                default:
                    Console.WriteLine("Некорректный ввод. Попробуйте снова.");
                    break;
            }
        }
    }
}