FROM jenkins/jenkins:lts-jdk17

RUN mkdir -p /var/jenkins_home/
COPY plugins.txt /var/jenkins_home/plugins.txt

RUN jenkins-plugin-cli --plugin-file /var/jenkins_home/plugins.txt
