@Library('ciinabox') _

pipeline {
  triggers {
      bitbucketPush()
  }

  environment {
    AWS_REGION = 'ap-southeast-2'
    OPS_ACCOUNT_ID = 'xxxxxxx'
    SOURCE_BUCKET = 'source.tools'
    PROJECT_NAME = 'hackday-arm' //Can't use dots (.) in cloudformation stackname
  }

  agent {
    node {
      label 'docker'
    }
  }
  
  stages {

    stage('build and Package') {
        agent {
            dockerfile {
                filename 'Dockerfile.build'
                reuseNode true
            }
        }
        parallel {
            stage("build x86") {
                steps {
                    sh "g++ hello.cpp -o hello-x86"
                }
            }
            stage("build arm") {
                steps {
                    sh "arm-linux-gnueabi-g++ hello.cpp -o hello-arm"
                }
            }
        }
    }
  }
}
