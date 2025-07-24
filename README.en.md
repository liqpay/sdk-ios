
# LiqPay iOS SDK

The `liqpay_ios.xcframework` framework provides tools to integrate LiqPay payments. 
The SDK contains all necessary dependencies and does not require CocoaPods, Carthage, or Swift Package Manager.

---

## Installation

1. Copy the `liqpay_ios.xcframework` file into your project's directory (e.g.,`Frameworks/`).
2. Add the framework to Xcode:
   - Open your project.
   - Drag  `liqpay_ios.xcframework` into the Project Navigator.
   - In the dialog that appears, select:
     - ✅ **Copy items if needed**
     - ✅ Add to the correct target (e.g., `YourAppTarget`)
3. Navigate to:
   ```
   Target → General → Frameworks, Libraries, and Embedded Content
   ```
   Ensure the framework is added with the following settings:
   - Embed: **Embed & Sign**

---

## Project settings

In the **Build Settings** of the application target, set the `Runpath Search Paths`:

```
@executable_path/Frameworks
```

If this setting is missing, add it manually. 
This is required for the correct loading of dynamic frameworks on physical devices (iPhone / iPad).

---

## Usage

In your project's source code, import the framework:

```swift
import liqpay_ios
```

Example of a payment request:

```swift
let payment = LiqPayPayment(
    data: "base64_encoded_data",
    signature: "base64_encoded_signature"
)

payment.payPrivatPay { success, error in
    if success {
        // Successful payment
    } else {
        // Error handling
    }
}
```

---

## Architectures

The framework supports the following architectures:

- `arm64` (devices)
- `x86_64`, `arm64` (simulators)

Built with `BUILD_LIBRARY_FOR_DISTRIBUTION = YES` and supports Swift ABI Stability.

---

## Technical Details

- Static linking of all dependencies
- Provided as `.xcframework`
- Compatible with Xcode 14 and later

---

## Support

For questions about integration or technical support, please contact the SDK development team or the project's support team.

[Documentation](https://www.liqpay.ua/doc)
