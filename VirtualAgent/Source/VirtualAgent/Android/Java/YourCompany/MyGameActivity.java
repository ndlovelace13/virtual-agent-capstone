package com.yourcompany;

import android.app.Activity;
import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationManager;
import android.os.Bundle;
import android.util.Log;

public class MyGameActivity extends com.epicgames.ue5.GameActivity {

    private static final String TAG = "MyGameActivity";

    // This method can now be called from Unreal C++ code
    public float[] AndroidThunkJava_GetCurrentLocation(Context context) {
        Location lastLocation = null;
        
        // Get the system's location service
        LocationManager locationManager = (LocationManager) context.getSystemService(Context.LOCATION_SERVICE);

        if (locationManager != null) {
            try {
                // Get the best provider for location (e.g., GPS or Network)
                String providerName = locationManager.getBestProvider(new Criteria(), false);
                lastLocation = locationManager.getLastKnownLocation(providerName);

                if (lastLocation == null) {
                    Log.w(TAG, "No last known location found. Trying to fetch a fresh location...");
                    // You might want to request updates for the location or retry here
                }
            } catch (Exception e) {
                Log.e(TAG, "Error getting location: " + e.getMessage());
                e.printStackTrace();
            }
        } else {
            Log.e(TAG, "LocationManager is null.");
        }

        // If no location is found, return default values (could also return null or some other fallback)
        if (lastLocation == null) {
            Log.w(TAG, "Location is null, returning default values.");
            return new float[] { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };  // Default location
        } else {
            // Return location data
            return new float[] {
                (float) lastLocation.getTime(),       // Timestamp
                (float) lastLocation.getLongitude(),  // Longitude
                (float) lastLocation.getLatitude(),   // Latitude
                lastLocation.getAccuracy(),           // Accuracy
                0.0f,                                 // No vertical accuracy on Android
                (float) lastLocation.getAltitude()    // Altitude
            };
        }
    }
}
