
# LiqPay iOS SDK

## 🌐 Other Languages

- [English](README.en.md)


Фреймворк `liqpay_ios.xcframework` надає інструменти для інтеграції з LiqPay-платежами.  
SDK містить усі необхідні залежності й не потребує використання CocoaPods, Carthage або Swift Package Manager.

---

## Встановлення

1. Скопіюйте файл `liqpay_ios.xcframework` у каталог вашого проєкту (наприклад, `Frameworks/`).
2. Додайте фреймворк до Xcode:
   - Відкрийте ваш проєкт.
   - Перетягніть `liqpay_ios.xcframework` до Project Navigator.
   - У вікні, що з’явиться, виберіть:
     - ✅ **Copy items if needed**
     - ✅ Додайте до відповідного Target (наприклад, `YourAppTarget`)
3. Перейдіть до:
   ```
   Target → General → Frameworks, Libraries, and Embedded Content
   ```
   Переконайтеся, що фреймворк додано з такими налаштуваннями:
   - Embed: **Embed & Sign**

---

## Налаштування проєкту

У **Build Settings** цільового застосунку потрібно вказати параметр `Runpath Search Paths`:

```
@executable_path/Frameworks
```

Якщо такого параметра немає – додайте його вручну. 
Це потрібно для правильного завантаження динамічних фреймворків на реальних пристроях (iPhone / iPad).

---

## Використання

У вихідному коді вашого проєкту підключіть фреймворк:

```swift
import liqpay_ios
```

Приклад виклику оплати:

```swift
let payment = LiqPayPayment(
    data: "base64_encoded_data",
    signature: "base64_encoded_signature"
)

payment.payPrivatPay { success, error in
    if success {
        // Успішний платіж
    } else {
        // Обробка помилки
    }
}
```

---

## Архітектури

Фреймворк підтримує такі архітектури:

- `arm64` (пристрої)
- `x86_64`, `arm64` (симулятори)

Зібрано з використанням `BUILD_LIBRARY_FOR_DISTRIBUTION = YES` та підтримує Swift ABI Stability.

---

## Технічні деталі

- Статичне лінкування всіх залежностей
- Поширюється як `.xcframework`
- Сумісний з Xcode 14 і вище

---

## Підтримка

З питань інтеграції та технічної підтримки звертайтеся до команди розробки SDK або до техпідтримки проєкту.


[Documentation](https://www.liqpay.ua/doc)

 
