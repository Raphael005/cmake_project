# ClamAV Setup on macOS

This document describes how to install, configure, and verify ClamAV for virus scanning.

## Installation

```bash
brew install clamav
```

## Configuration

### 1. Configure freshclam (virus database updater)

```bash
cp /opt/homebrew/etc/clamav/freshclam.conf.sample /opt/homebrew/etc/clamav/freshclam.conf
sed -i '' 's/^Example/#Example/' /opt/homebrew/etc/clamav/freshclam.conf
```

### 2. Update virus database

```bash
freshclam
```

### 3. Configure clamd daemon

```bash
cp /opt/homebrew/etc/clamav/clamd.conf.sample /opt/homebrew/etc/clamav/clamd.conf
sed -i '' 's/^Example/#Example/' /opt/homebrew/etc/clamav/clamd.conf
sed -i '' 's|^#LocalSocket /tmp/clamd.sock|LocalSocket /tmp/clamd.sock|' /opt/homebrew/etc/clamav/clamd.conf
```

### 4. Start the daemon

```bash
clamd
```

## Usage

### On-demand scanning (without daemon)

```bash
clamscan /path/to/file
clamscan -r /path/to/directory
```

### Daemon-based scanning (faster)

```bash
clamdscan /path/to/file
clamdscan -r /path/to/directory
```

## Verification

### Check daemon status

```bash
pgrep -l clamd
clamdscan --version
```

### Test detection with EICAR file

```bash
echo 'X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*' > /tmp/eicar_test.txt
clamdscan /tmp/eicar_test.txt
rm /tmp/eicar_test.txt
```

Expected output: `Eicar-Signature FOUND`

## Keeping virus definitions updated

Run periodically to update the virus database:

```bash
freshclam
```

Or set up a cron job / launchd service for automatic updates.
