package com.example.myapplication

import android.Manifest
import android.content.pm.PackageManager
import android.location.Location
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.example.myapplication.ui.theme.MyApplicationTheme
import com.google.android.gms.location.FusedLocationProviderClient
import com.google.android.gms.location.LocationServices

class MainActivity : ComponentActivity() {
    private lateinit var fusedLocationClient: FusedLocationProviderClient

    // State to hold the user's coordinates and distance to Hayden Pillar
    private var userCoordinates by mutableStateOf<Pair<Double, Double>?>(null)
    private var distanceToHaydenPillar by mutableStateOf<Double?>(null)

    // Define Hayden Pillar's location
    private val haydenPillarLocation = Location("Hayden Pillar").apply {
        latitude = 33.4192977
        longitude = -111.9351723
    }

    // Register the permission request launcher
    private val requestPermissionLauncher = registerForActivityResult(
        ActivityResultContracts.RequestPermission()
    ) { isGranted: Boolean ->
        if (isGranted) {
            getLocation()
        } else {
            // Handle permission denial
            println("Location permission denied")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Initialize FusedLocationProviderClient
        fusedLocationClient = LocationServices.getFusedLocationProviderClient(this)

        // Request location permission
        requestPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)

        setContent {
            MyApplicationTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    Greeting(
                        name = "Lorenzo",
                        coordinates = userCoordinates,
                        distance = distanceToHaydenPillar,
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }

    private fun getLocation() {
        if (checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED ||
            checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {

            fusedLocationClient.lastLocation
                .addOnSuccessListener { location: Location? ->
                    if (location != null) {
                        // Update the state with the location coordinates
                        userCoordinates = Pair(location.latitude, location.longitude)
                        println("Location: ${location.latitude}, ${location.longitude}")

                        // Calculate distance to Hayden Pillar in meters
                        val distanceInMeters = location.distanceTo(haydenPillarLocation).toDouble()
                        // Convert meters to miles
                        distanceToHaydenPillar = distanceInMeters * 0.000621371
                        println("Distance to Hayden Pillar: ${distanceToHaydenPillar} miles")
                    } else {
                        println("No location found.")
                    }
                }
                .addOnFailureListener { e ->
                    // Handle failure
                    println("Failed to get location: ${e.message}")
                }
        } else {
            // Permission not granted
            requestPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)
        }
    }
}

@Composable
fun Greeting(name: String, coordinates: Pair<Double, Double>? = null, distance: Double? = null, modifier: Modifier = Modifier) {
    Text(
        text = buildString {
            append("Hello $name!")
            coordinates?.let {
                append("\nCoordinates: Latitude: ${it.first}, Longitude: ${it.second}")
            }
            distance?.let {
                append("\nDistance to Hayden Pillar: ${String.format("%.2f", it)} miles") // Format to 2 decimal places
            }
        },
        modifier = modifier
    )
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    MyApplicationTheme {
        Greeting("Android")
    }
}
