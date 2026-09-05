# 📐 Mechanical & Pontoon Specifications (Catamaran Hull)

## Hull Dimensions
* **Type:** Catamaran Dual-Pontoon Configuration
* **Pontoon Material:** High-Density PVC Pipe (Outer Diameter $D = 90\text{ mm}$, Length $L = 1000\text{ mm}$)
* **Pontoon Spacing:** $350\text{ mm}$ center-to-center
* **Overall Vehicle Dimensions:** $1000 \times 450 \times 250\text{ mm}$ (Length x Width x Height)

## Buoyancy Dynamics Calculations
* **Volume per meter of 90mm pipe:** 
  \[ V_{1m} = \pi \cdot \frac{D^2}{4} \cdot 1.0 = \pi \cdot \frac{0.09^2}{4} \cdot 1.0 \approx 0.00636\text{ m}^3 \]
* **Max Archimedes Buoyant Force (2x 1.0m pipes):**
  \[ F_{A,total} = 2 \cdot (1000\text{ kg/m}^3 \cdot 9.81\text{ m/s}^2 \cdot 0.00636\text{ m}^3) \approx 124.8\text{ N} \quad (\approx 12.7\text{ kgf}) \]
* **Total Robot Mass:** $3.25\text{ kg}$ (Total Weight $P \approx 31.88\text{ N}$)
* **Reserve Buoyancy:** **74.45%** (Static Draft = $45\text{ mm}$, 25% pontoon height)
