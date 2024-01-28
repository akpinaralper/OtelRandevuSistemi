# Otel Randevu Sistemi

Bu C dilinde yazılmış basit bir otel randevu sistemi örneğidir. Bu program, müşterilerin otel odaları için rezervasyon yapmalarını, mevcut rezervasyonları görüntülemelerini ve rezervasyonları iptal etmelerini sağlar.

## Kullanım

Programı çalıştırdığınızda, bir menü görüntülenir ve kullanıcı istediği işlemi seçebilir. Menü şu seçenekleri içerir:

1. Rezervasyon Yap
2. Rezervasyonları Göster
3. Rezervasyon İptal Et
4. Çıkış

Her seçenek, kullanıcıya belirli bir işlem yapma yeteneği sağlar.

## Yapı ve Fonksiyonlar

- `struct Customer`: Müşteri bilgilerini içeren yapı.
- `struct Hotel`: Oteli temsil eden yapı, rezervasyonları içerir.
- `displayMenu()`: Kullanıcıya menüyü gösteren fonksiyon.
- `makeReservation()`: Rezervasyon yapma fonksiyonu.
- `displayReservations()`: Mevcut rezervasyonları görüntüleme fonksiyonu.
- `cancelReservation()`: Rezervasyon iptal etme fonksiyonu.
